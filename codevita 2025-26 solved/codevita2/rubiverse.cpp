#include <bits/stdc++.h>
using namespace std;
const int topo[8][3] = {
    {1, 2, 4}, {0, 3, 5}, {0, 3, 6}, {1, 2, 7},
    {0, 5, 6}, {1, 4, 7}, {2, 4, 7}, {3, 5, 6}
};

int face_mp[26][4];
char net[4][4];
bool vis[4][4];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

string stickers;
char order_arr[26];
int ord_cnt = 0;

int _next(int pivot, int a, int b){
    for(int v : topo[pivot]) if(v != a && v != b) return v;
    return -1;//not found
}

void unfold(int r,int c,const vector<int>& vc){
    vis[r][c] = true;
    int f = net[r][c] - 'A';
    for(int i=0;i<4;i++) face_mp[f][i] = vc[i];

    for(int d=0;d<4;d++){
        int nr=r+dr[d], nc=c+dc[d];
        if(nr<0||nr>=4||nc<0||nc>=4) continue;
        if(net[nr][nc]=='.'||vis[nr][nc]) continue;
        vector<int> nxt(4);
        if(d==0){
            nxt[2]=vc[0]; nxt[3]=vc[1];
            nxt[0]=_next(vc[0],vc[1],vc[2]);
            nxt[1]=_next(vc[1],vc[0],vc[3]);
        }else if(d==1){
            nxt[0]=vc[2]; nxt[1]=vc[3];
            nxt[2]=_next(vc[2],vc[3],vc[0]);
            nxt[3]=_next(vc[3],vc[2],vc[1]);
        }else if(d==2){
            nxt[1]=vc[0]; nxt[3]=vc[2];
            nxt[0]=_next(vc[0],vc[2],vc[1]);
            nxt[2]=_next(vc[2],vc[0],vc[3]);
        }else{
            nxt[0]=vc[1]; nxt[2]=vc[3];
            nxt[1]=_next(vc[1],vc[3],vc[0]);
            nxt[3]=_next(vc[3],vc[1],vc[2]);
        }
        unfold(nr,nc,nxt);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int sr=-1, sc=-1;
    for(int i=0;i<4;i++){
        string row; cin>>row;
        for(int j=0;j<4;j++){
            net[i][j] = row[j];
            vis[i][j] = false;
            if(net[i][j] != '.'){
                if(sr==-1){ sr=i; sc=j; }
                order_arr[ord_cnt++] = net[i][j];
            }
        }
    }
    cin>>stickers;
    string query; cin>>query;
    vector<int> base = {0,1,2,3};
    unfold(sr,sc,base);
    int common = -1;
    int f1=query[0]-'A', f2=query[1]-'A', f3=query[2]-'A';
    for(int v=0;v<8;v++){
        bool a=false,b=false,c=false;
        for(int k=0;k<4;k++) if(face_mp[f1][k]==v) a=true;
        for(int k=0;k<4;k++) if(face_mp[f2][k]==v) b=true;
        for(int k=0;k<4;k++) if(face_mp[f3][k]==v) c=true;
        if(a&&b&&c){ common=v; break; }
    }

    string out="";
    for(char fc : query){
        int fi = fc - 'A';
        int off=0;
        for(int k=0;k<4;k++) if(face_mp[fi][k]==common){ off=k; break; }
        int idx=-1;
        for(int i=0;i<6;i++) if(order_arr[i]==fc){ idx=i*4; break; }
        out += stickers[idx + off];
    }

    cout<<out;
    return 0;
}
