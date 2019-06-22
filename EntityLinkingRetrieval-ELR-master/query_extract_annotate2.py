import tagme
import json
import sys

tagme.GCUBE_TOKEN = "6db5eee7-8be2-410b-8657-b7ba3e234447-843339462"
lunch_annotations = tagme.annotate("My favourite meal is Mexican burritos.")

queries=[]

with open(sys.argv[1]) as json_file:
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
        main_cat=str(ann.entity_title).decode("utf-8").replace(u" ", "_").encode("utf-8")
        main_cat.decode("utf-8").replace(u" ", "_").encode("utf-8")
        dbpedia=("<dbpedia:"+main_cat+">")
        annotaion_json_file[query_no]['interpretations']['0']['annots'][ann.mention].update({"uri":dbpedia})
        print (ann)
        annotaion_json_file[query_no]['interpretations']['0'].update({"prob": 1})
        annotaion_json_file[query_no].update({"query":query})




with open('//elr_files//EntityLinkingRetrieval-ELR-master//data//extracted_annotations_A.json', 'w') as outfile:
    json.dump(annotaion_json_file, outfile , indent=4)



