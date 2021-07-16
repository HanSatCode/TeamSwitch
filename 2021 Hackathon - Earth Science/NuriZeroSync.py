# 크롤링에 필요한 모듈들
import requests                # 기상청 사이트에서 데이터 받아오기 담당
from bs4 import BeautifulSoup  # 기상청 사이트 데이터에서 꼭 필요한 데이터만 HTML로 추출하기 담당

# 계속 작동되도록 하기 위해 필요한 모듈
import time                    # 1시간 마다 데이터 갱신되므로 페이지 리디렉션을 위함

# 아두이노 모듈
import serial
arduino = serial.Serial('COM3', 9600)

while True :
    # 날씨 정보 찾으러 가기 담당
    source = requests.get('https://www.weather.go.kr/weather/observation/currentweather.jsp')  # 여기서 데이터를 받아옴
    soup = BeautifulSoup(source.content, "html.parser")  # 받아온 데이터들을 HTML 형태로 바꿈

    table = soup.find('table', {'class': 'table_develop3'})
    data = []

    # 프로그램의 시작
    '''
    print("=" * 30)
    print("\n<How's the weather?>\n")
    print("=" * 30)
    '''
    for tr in table.find_all('tr'):
        tds = list(tr.find_all('td'))
        for td in tds:
            if td.find('a'):
                point = td.find('a').text
                temp = tds[5].text
                humidity = tds[9].text
                data.append([point, temp, humidity])
    # ======<출력 부분 제외>==========================================================
                '''
                print("{0:<7} {1:<7} {2:<7}".format(point, temp, humidity))
                
    
    
    print("=" * 30)
    print("\n모든 도시의 데이터 출력을 마쳤습니다.\n")
    print("=" * 30)
    
    print(data)
    '''
    # ======<출력 부분 제외>==========================================================
    with open('weather.csv', 'w') as f:  # 가져온 데이터를 csv 형식으로 저장
        f.write('지역, 온도, 습도\n')
        for i in data:
            f.write('{0},{1},{2}\n'.format(i[0], i[1], i[2]))

    # 대구의 온도＆습도 구하기
    import pandas as pd

    df = pd.read_csv('weather.csv', index_col='지역', encoding='euc-kr')

    df_Daegu = df.loc['대구']                   # CSV에서 대구의 온도와 습도값 가져오기

    df_Daegu_Temp = df_Daegu[0]                 # 대구의 온도 분리
    df_Daegu_Humility = df_Daegu[1]             # 대구의 습도 분리

    A = int(df_Daegu_Temp)                      # 온도 정수화
    B = int(df_Daegu_Humility)                  # 습도 정수화

    # From python To arduino
    A = str(A)
    B = str(B)
    Trans = A + B                               # 아두이노로 데이터 옮기기 위해서 변환
    Trans = Trans.encode('utf-8')
    Trans = int(Trans)

    arduino.write(Trans)                        # 변환값 아두이노로 전송
    print(Trans)
    print(type(Trans))

    # 1시간 마다 데이터 리디렉션
    time.sleep(3600)
