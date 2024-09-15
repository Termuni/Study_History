import requests
import oracledb 

url = 'http://www.ssf-kpi.kr:8080/kpiLv1/kpiLv1Insert'
data ={
     "KPILEVEL1" :
     [
     {"kpiCertKey": "e169-aaf0-3b11-05ef","ocrDttm": "20240909", 
             "systmOprYn": "Y", 
             "trsDttm": "20240909101520"}
     ]
}
http_post_request = requests.post(url,json=data)
print(http_post_request.text)
print(http_post_request.status_code)

url = 'http://www.ssf-kpi.kr:8080/kpiLv2/kpiLv2Insert'

data ={
"KPILEVEL2" :
[
{"kpiCertKey": "e169-aaf0-3b11-05ef", "ocrDttm": "20240909", 
 "kpiFldCd": "P", "kpiDtlCd": "B", "kpiDtlNm": " 생산량 증가", 
 "achrt": "90", "trsDttm": "20240909103920"},
{"kpiCertKey": "e169-aaf0-3b11-05ef", "ocrDttm": "20240909", 
 "kpiFldCd": "Q", "kpiDtlCd": "B", "kpiDtlNm": "불량률감소", 
 "achrt": "51", "trsDttm": "20240909103920"}
]
}
http_post_request = requests.post(url,json=data)
print(http_post_request.text)
print(http_post_request.status_code)

oracledb.init_oracle_client()
con = oracledb.connect(user="TRUNS", password="TRUNS", dsn="202.68.233.246:1521/orcl")   # DB에 연결 (호스트이름 대신 IP주소 가능)
cursor = con.cursor()   # 연결된 DB 지시자(커서) 생성
print('데이터베이스 연결 성공~!!!')

cursor.execute("select * from MST0TB002")       # DB 명령 실행 (cursor가 임시 보관)
out_data = cursor.fetchall()   # cursor가 임시 보관한 내용을 out_data에 저장 (결과는 리스트)
# out_data 내용 출력해보기
for record in out_data :
	print(record)
	
con.close() 
