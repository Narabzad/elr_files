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
    
    query=line.split(':')[1].rstrip().strip()
    query_no=line.split(':')[0]
    query_json_file[query_no] = {}
    query_json_file.update({query_no:query})

with open('//elr_files//EntityLinkingRetrieval-ELR-master//data//extracted_queries.txt', 'w') as outfile:
    json.dump(query_json_file, outfile , indent=4)
