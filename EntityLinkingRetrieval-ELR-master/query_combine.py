import tagme
import json
import sys 
import logging
logger = logging.getLogger()
logger.disabled = True

tagme.GCUBE_TOKEN = "6db5eee7-8be2-410b-8657-b7ba3e234447-843339462"
query_file=open(sys.argv[1],'r')


dq = {}
data = {}
lines=query_file.readlines()

if '<top>' in lines[0]:
    query_number=''
    for line in lines:

        if'<num>' in line :
            query_number= line.split(':')[1].rstrip().strip()
        if'<title>' in line :
            query=line.replace('<title>','').strip()
            if query=='':
                query=line
                query=lines[l+1].strip()
            dq[query_number]=query
            query_number=''
            query=''
        l=l+1
elif ':' in lines[0]:
    for line in lines:
        query_number = line.split(':')[0].rstrip().strip()
        query = line.split(':')[1].strip().rstrip()
        dq[query_number] = query

annotaion_json_file = {}
query_json_file={}

for qno,qts in dq.items():
    query=qts
    query_no=qno
    lunch_annotations = tagme.annotate(query)
    if lunch_annotations is not None:
        data[query_no] = {}
        data[query_no]['interpretations']={}
        data[query_no]['interpretations']['0']={}
        data[query_no]['interpretations']['0']['annots']={}
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

with open('//elr_files//EntityLinkingRetrieval-ELR-master//data//extracted_annotations.json', 'w') as outfile:
    json.dump(data, outfile , indent=4)
with open('//elr_files//EntityLinkingRetrieval-ELR-master//data//extracted_queries.json', 'w') as outfile:
    json.dump(dq, outfile , indent=4)
