```c++
void myfoo(){
    /** String Methods - Tests:
    * name.clear();
    * >>> name -> ""
    *
    * name.append("@append message");
    * >>> name -> "Bro John@append message"
    *
    * char nameAt = name.at(0);
    * >>> nameAt -> 'B'
    *
    * name.insert(0, "#");
    * >>> name -> "#Bro John"
    *
    * name.erase(1,3);
    * >>> name -> "BJohn"
    *
    */


    std::string name = "Bro John";
    std::cout << name << '\n';
}
```

```c++
void myfoo(){
    /** 什什麼是srand()
     * 在 stdlib.h 標頭檔中
     * srand() 用来设置 rand() 产生随机数时的随机数种子。
     * 参数 seed 必须是个整数。
     * 如果每次 seed 都设相同值，rand() 所产生的随机数值每次就会一样。
     *
     * 利用mod: 設 mod x，取得小於x的數字。
    */
    srand(time(NULL));


    int num = rand() % 6 + 1;

    std::cout << num << '\n';

}
```

```c++
void foo(){
    /** Array
     *
     * 宣告方法1 -- 直接寫入:
     * std::string car[] = {"car1", "car2", "car3"};
     *
     * 宣告方法2 -- 宣告大小:
     * int test[3];
     * Say. 這個陣列的長度為3，未來可以放入3個元素。
     *
     * Note. 直接印出陣列只會傳回記憶體起始位置。
     *
     * Q. What is its length? How can we traversal this array?
     * 1. Using sizeof() : 可以得出這個陣列占多少記憶體空間，單位是byte。除以每個元素大小(即, sizeof(元素))即可得長度。
     * 2. Using foreach loop
    */


    std::string car[] = {"car1", "car2", "car3"};


    // 除以型態大小
    for(int i = 0; i < sizeof(car)/ sizeof(std::string);i++){
        std::cout << car[i] << '\n';
    }

    // 利用陣列元素型態相同之原理
    for(int i = 0; i < sizeof(car)/ sizeof(car[0]);i++){
        std::cout << car[i] << '\n';
    }

}
```
