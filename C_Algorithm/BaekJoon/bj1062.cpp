// https://www.acmicpc.net/problem/1062

/*
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 
그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 
김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 
김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 
학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

첫째 줄에 단어의 개수 N과 K가 주어진다. 
N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다. 
둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 
단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.

예제 입력
3 6
antarctica
antahellotica
antacartica
*/



//필수로 배워야 하는 영어 : a, c, i, n, t
//시작하자마자 위에 해당 하는 것 다 지우기
//rrr, hello, ry
//남은 것들로 조합 짜서 확인하기
//최대 21C10번 동작 = 35만회
//조합 코드 짜기
//우선 string으로 해서 벡터, 다 지우고 
//a c i n t 전부 빼

