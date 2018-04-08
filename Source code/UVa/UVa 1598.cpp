//UVa 1598 交易所 Exchange
#include<bits/stdc++.h>
using namespace std;

struct CMD {                        //存入每条指令
    string cmd;                     //操作
    int size, price;                //价格与数量
    CMD(string kind, int x = 0, int y = 0): //构造函数
    cmd(kind), size(x), price(y) {}
};
map<int, set<int> > BUY, SELL;    //价格到指令编号的映射  
map<int, int> BUY_VAL, SELL_VAL;   //价格到数量的映射
vector<CMD> D;                      //存每条指令

void trade(int kind) {
    while (!BUY.empty() && !SELL.empty()) { //如果买入和卖出都不为空
        if (BUY.rbegin()->first >= SELL.begin()->first){    //如果买入的最高价格低于大于卖出的最低价格
            set<int> &v1 = BUY.rbegin()->second;
            set<int> &v2 = SELL.begin()->second;
            int aid = *v1.begin(), bid = *v2.begin();       //aid=买入最高价的最小数量    bid=卖出最低价的最小数量
            int z = min(D[aid].size, D[bid].size);          //z=买入和卖出中的成交数量
            printf("TRADE %d %d\n", z, kind ? D[aid].price : D[bid].price); //成交数量和价格，如果现在试买入则输出买入价格，否则反之
            D[aid].size -= z, D[bid].size -= z;             //买入和卖出数量全部减掉z；
            BUY_VAL[D[aid].price] -= z, SELL_VAL[D[bid].price] -= z;   //映射表中也同上 
            if (D[aid].size == 0)
                v1.erase(aid);
            if (D[bid].size == 0)
                v2.erase(bid);
            if (v1.size() == 0)
                BUY.erase(D[aid].price);
            if (v2.size() == 0)
                SELL.erase(D[bid].price);               //如果有数量为0 ，则删除
        } else {
            return;
        }
    }
}
void print() {
    while (BUY_VAL.size() && BUY_VAL.rbegin()->second == 0) {   //如果购买的数量不为0并且最大价格的ID为0
        BUY_VAL.erase(BUY_VAL.rbegin()->first);                 //则一直删除到不为零为止
    }
    while (SELL_VAL.size() && SELL_VAL.begin()->second == 0) {  
        SELL_VAL.erase(SELL_VAL.begin()->first);
    }
    printf("QUOTE ");
    if (BUY_VAL.size()) {                       //如果买入数量不为0
        printf("%d %d", BUY_VAL.rbegin()->second, BUY_VAL.rbegin()->first); //则输出价格和数量
    } else {
        printf("0 0");                          //不然则输出0 0
    }
    printf(" - ");
    if (SELL_VAL.size()) {
        printf("%d %d", SELL_VAL.begin()->second, SELL_VAL.begin()->first);
    } else {
        printf("0 99999");
    }
    puts("");                                   //换行
}
void clear(){
    BUY.clear(), SELL.clear();      
    BUY_VAL.clear(), SELL_VAL.clear();
    D.clear();
}
int main() {
    int Q, cases = 0;
    char cmd[16];
    while (scanf("%d", &Q) == 1) {      //指令数量
        if (cases++)    puts("");      //如果不是第一行则输出换行
        
        clear();

        int size, price, id;           //数量，价格和指令编号
        for (int i = 0; i < Q; i++) {   
            scanf("%s", cmd);           //读取字符串存入cmd
            if (!strcmp(cmd, "BUY")) {      //如果是买入指令
                scanf("%d %d", &size, &price);  //读取数量与价格
                BUY[price].insert(i);       //买入价格集合中加入当前操作ID
                BUY_VAL[price] += size;     //买入价格映射中加上当前数量
                D.push_back(CMD("BUY", size, price));  //往vector 中存入当前操作 
                trade(0);
            } else if (!strcmp(cmd, "SELL")) {
                scanf("%d %d", &size, &price);
                SELL[price].insert(i);
                SELL_VAL[price] += size;
                D.push_back(CMD("SELL", size, price));
                trade(1);

            } else if (!strcmp(cmd, "CANCEL")) {    //如果是取消操作
                scanf("%d", &id), id--;             //读取取消的id
                D.push_back(CMD("CANCEL", id));     //将命令存入vector中
                if (D[id].cmd == "BUY") {           //如果要取消的操作是购买操作
                    BUY[D[id].price].erase(id);         //删除映射表价格中的ID编号
                    if (BUY[D[id].price].size() == 0)   //如果这个价格的集合数量为0
                        BUY.erase(D[id].price);         //则删除这个价格
                    BUY_VAL[D[id].price] -= D[id].size; //减掉集合的对应数量， 
                    D[id].size = 0;                 //D的大小变成0；
                }
                if (D[id].cmd == "SELL") {
                    SELL[D[id].price].erase(id);        //删除卖出中这个价格的ID
                    if (SELL[D[id].price].size() == 0)  //如果剩余的ID为0，则删掉这个集合
                        SELL.erase(D[id].price);        
                    SELL_VAL[D[id].price] -= D[id].size;   //减掉对应数量
                    D[id].size = 0;
                }
            }
            print();
        }
    }
    return 0;