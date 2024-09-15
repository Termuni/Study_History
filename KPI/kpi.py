import requests
import oracledb 
import json
from datetime import datetime as date


def Get_URL(url_num = 0):
    if url_num == 1:
        url = 'http://www.ssf-kpi.kr:8080/kpiLv1/kpiLv1Insert'
    elif url_num == 2:
        url = 'http://www.ssf-kpi.kr:8080/kpiLv2/kpiLv2Insert'
    elif url_num == 3:
        url = 'http://www.ssf-kpi.kr:8080/kpiLv2/kpiLv3Insert'
    else:
        print("Insert Correct Kpi LEVEL!")
    return url

def Set_Cert_KEY(key = 'e169-aaf0-3b11-05ef'):
    return key

def Set_Time():
    now = date.now()
    return now

def Check_and_Add(check, ret):
    if check < 10:
        ret = ret + '0'
    ret = ret + str(check)
    return ret

def Set_Year_Month_Date(now = date.now()):
    if isinstance(now, date):
        ymd = str(now.year)
        ymd = Check_and_Add(now.month, ymd)
        ymd = Check_and_Add(now.day, ymd)
        return ymd
    else:
        print(f"ERR : NOT A CORRECT INPUT for Set Date, {now}")

def Set_Year_to_Sec(now = date.now()):
    if isinstance(now, date):
        ymd = str(now.year)
        ymd = Check_and_Add(now.month, ymd)
        ymd = Check_and_Add(now.day, ymd)
        ymd = Check_and_Add(now.hour, ymd)
        ymd = Check_and_Add(now.minute, ymd)
        ymd = Check_and_Add(now.second, ymd)
        return ymd

def Set_Data_LV1(key, ymd, yts, systmOprYn = 'Y'):
    data = {
        "KPILEVEL1" :
        [
            {
                "kpiCertKey": key,
                "ocrDttm": ymd, 
                "systmOprYn": systmOprYn, 
                "trsDttm": yts
            }
        ]
    }
    return data
    

def Set_Data_LV2(key, ymd, yts, systmOprYn = 'Y'):
    data = {
        "KPILEVEL2" :
        [
            {
                "kpiCertKey": "e169-aaf0-3b11-05ef",
                "ocrDttm": "20240909", 
                "kpiFldCd": "P", 
                "kpiDtlCd": "B", 
                "kpiDtlNm": " 생산량 증가", 
                "achrt": "90", 
                "trsDttm": "20240909103920"
            },
            {
                "kpiCertKey": "e169-aaf0-3b11-05ef", 
                "ocrDttm": "20240909", 
                "kpiFldCd": "Q", 
                "kpiDtlCd": "B", 
                "kpiDtlNm": "불량률감소", 
                "achrt": "51", 
                "trsDttm": "20240909103920"
            }
        ]
    }
    return data

if __name__ == "__main__":    
    t = Set_Time()
    ymd = Set_Year_Month_Date(t)
    yts = Set_Year_to_Sec(t)
    print(ymd)
    print(yts)