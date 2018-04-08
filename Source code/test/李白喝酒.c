int ans = 0;
for (int i = 0; i < (1<<14); ++i) {	//枚举所有结果
    int tot_1 = 0;					//店数
    int tot_0 = 0;					//花数
    int num = 2;					//壶里酒的数量
    for (int j = 0; j < 14; ++j) {
        if (i&(1 << j)) { // 这里判断二进制 i 从右数第 j + 1 位是否为 1	
            tot_1++;			//是1的话，则点数+1
            num = num * 2;		//酒量*2
        } else {
            tot_0++;			
            num = num - 1;
        }  
    }
    if (tot_1 == 5 && tot_0 == 9 && num == 1) {
        ++ans; // 记录合法方案数
    }
}
