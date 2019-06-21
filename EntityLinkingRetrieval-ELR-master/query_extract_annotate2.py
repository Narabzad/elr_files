import tagme
import json
import sys

tagme.GCUBE_TOKEN = "6db5eee7-8be2-410b-8657-b7ba3e234447-843339462"
lunch_annotations = tagme.annotate("My favourite meal is Mexican burritos.")

queries=[]
#query_file=open('','r').readlines()

query_file=open(sys.argv[1],'r').readlines()


with open('rb04_q.json') as json_file:
    data = json.load(json_file)
    for keys,vals in data.items():
        queries.append(keys+":"+vals)

annotaion_json_file = {}

for line in queries:
    query=line.split(':')[1].rstrip().strip()
    query_no=line.split(':')[0]
    annotaion_json_file[query_no] = {}
    annotaion_json_file[query_no]['interpretations']={}
    annotaion_json_file[query_no]['interpretations']['0']={}
    annotaion_json_file[query_no]['interpretations']['0']['annots']={}

    entities=[]
    lunch_annotations = tagme.annotate(query)
    for ann in lunch_annotations.get_annotations(0.1):
        entities.append(ann)
        annotaion_json_file[query_no]['interpretations']['0']['annots'][ann.mention]={}
        annotaion_json_file[query_no]['interpretations']['0']['annots'][ann.mention].update({"score":ann.score})
        dbpedia="<dbpedia:"+str(ann.entity_title).replace(' ','_')+">"
        annotaion_json_file[query_no]['interpretations']['0']['annots'][ann.mention].update({"uri":dbpedia})
        print (ann)
        annotaion_json_file[query_no]['interpretations']['0'].update({"prob": 1})
        annotaion_json_file[query_no].update({"query":query})




with open('extracted annotations.json', 'w') as outfile:
    json.dump(annotaion_json_file, outfile , indent=4)



