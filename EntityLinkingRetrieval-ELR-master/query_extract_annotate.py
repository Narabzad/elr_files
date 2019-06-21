import json
import sys


queries=[]
query_file=open(sys.argv[1],'r').readlines()
for line in query_file:
    if'<num>' in line :
        query_number= line.split(':')[1].rstrip().strip()
    if'<title>' in line :
        query=line.replace('<title>','').strip()
        queries.append(query_number + ':' + query)
        query_number=''
        query=''
        
query_json_file={}

for line in queries:

    query_json_file[query_no] = {}
    query_json_file.update({query_no:query})

with open('//elr_files//EntityLinkingRetrieval-ELR-master//data//query_json_file.txt', 'w') as outfile:
    json.dump(query_json_file, outfile , indent=4)
