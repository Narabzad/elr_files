import tagme
import json
import sys 

tagme.GCUBE_TOKEN = "6db5eee7-8be2-410b-8657-b7ba3e234447-843339462"
query_file=open(sys.argv[1],'r').readlines()
dq = {}
data={}
query_number=''
for line in query_file:
    if'<num>' in line :
        query_number= line.split(':')[1].rstrip().strip()
    if'<title>' in line :
        query=line.replace('<title>','').strip()
        dq[query_number]=query
        query_number=''
        query=''
annotaion_json_file = {}
query_json_file={}

for qno,qts in dq.items():
    query=qts
    query_no=qno
    data[query_no] = {}
    data[query_no]['interpretations']={}
    data[query_no]['interpretations']['0']={}
    data[query_no]['interpretations']['0']['annots']={}
    lunch_annotations = tagme.annotate(query)
    for ann in lunch_annotations.get_annotations(0.1):
        try:
            dbpedia = "<dbpedia:" + str(ann.entity_title).replace(' ', '_') + ">"
            done=1
        except:
            done=0
        if done==1:
            data[query_no]['interpretations']['0']['annots'][ann.mention]={}
            data[query_no]['interpretations']['0']['annots'][ann.mention].update({"score":ann.score})
            data[query_no]['interpretations']['0']['annots'][ann.mention].update({"uri":dbpedia})
    data[query_no]['interpretations']['0'].update({"prob": 1})
    data[query_no].update({"query":query})

with open('//elr2//EntityLinkingRetrieval-ELR-master//data//A_annotate.txt', 'w') as outfile:
    json.dump(data, outfile , indent=4)
with open('//elr2//EntityLinkingRetrieval-ELR-master//data//A_query.txt', 'w') as outfile:
    json.dump(dq, outfile , indent=4)
