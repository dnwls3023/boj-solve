#include <iostream>
using namespace std;

int n,m;
string board[11];

/*
    백준 13460번 틀린 코드 (조만간 수정 예정) : 
    https://github.com/dnwls3023/
    
    접근방법:
    모든 방향을 돌려보면서 재귀호출

    알고리즘 설명:
    
    왜 틀린 알고리즘인가? : 우선 문제를 잘못읽음.(가장 큰 실수) R만 움직이는 것이라고 이해했었고 B를 도착점, O를 게임오버 지점이라고 착각했음. 
    (이렇게 이해했다고 가정하고 프로그램을 돌려봐도 제대로 작동하는지조차 의문임. 아마 안돌아갈듯)
    
    하지만 문제가 요구하는 바는 B와 R은 둘다 구슬이며 동시에 움직인다. 그리고 O는 게임오버 지점이 아니라 도착지점이며 빨간 구슬이 O에 들어가면 성공
    파랑 구슬이 O에 들어가면 실패다. 사실 여기까지는 구현할 수 있을 것 같았음.
    근데 어디서 막혔냐면 B와 R은 겹쳐지는 것이 불가능하고 만약에 닿는일이 생긴다면 벽으로 간주하는 부분을 어떻게 구현해야할지 모르기 때문에 막혔다.
    (조만간 다시 해결할 생각 : 숙제)
    
    이걸 구현했다고 가정하면 상하좌우 모든 가능성을 검토해가면서(재귀호출) 도착할 수 있는 최소 횟수를 구하면 끝난다. 
*/

/*
    IDX 0은 R의 좌표,
    IDX 1은 B의 좌표,
    IDX 2은 O의 좌표임.
*/ 
pair<int,int> p[3];
int answer = 11;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int solve(int y,int x,int cnt){
    board[y][x] = 'R';
    for(int i = 0 ;i<4;++i){
        int k = 1;
        // 종료조건 : # B O 를 만났을 경우
        while(board[y+dy[i]*k][x+dx[i]*k] == '.'){
            // 해당위치로 이동
            k++;
        }
        
        // 도착했거나 횟수가 10회를 넘어가면
        if(board[y+dy[i]*k][x+dx[i]*k] == 'B' || cnt == 10) {
            // 횟수를 반환
            return answer = min(answer,cnt);
        }

        // 벽을 만나서 종료된 것이라면
        if(board[y+dy[i]*k][x+dx[i]*k] == '#') {
            // k의 값을 마지막.의 위치상태로 되돌리고
            k--;
        }

        // 게임오버인 경우
        if(board[y+dy[i]*k][x+dx[i]*k] == 'O'){
            // -1을 반환
            answer = 987654321;
        }

        // 그 이외의 경우 재귀호출
        solve(y+dy[i]*k,x+dx[i]*k,cnt+1);
    }
}

int main(void){
    cin>>n>>m;
    for(int i = 0 ; i<n;++i) cin>>board[i];

    


    for(int i = 0; i<n;++i){
        for(int j= 0 ;j<m;++j){
            if(board[i][j] == 'R'){
                p[0].first = i;
                p[0].second = j;
            }
            else if(board[i][j] == 'B'){
                p[1].first = i;
                p[1].second = j;
            }
            else if(board[i][j] == 'O'){
                p[2].first = i;
                p[2].second = j;
            }
        }
    }

    solve(p[0].first,p[0].second,0);

    cout<<answer<<endl;
        

    return 0;
}
