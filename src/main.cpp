#include <iostream>

void foo(){
    /** Foreach loop -- Array traversal
    */
    int myArr[] = {1, 2, 3};
    std::cout << sizeof(myArr)/ sizeof(myArr[0]);

}

/**
 * gcd - rec.
*/
int gcdRec(int a, int b, int count){
    if (a % b ==0){
        std::cout << "calling: "<< count << '\n';
        return b;
    }else{
        return gcdRec(b, a % b, count + 1);
    }
}
/**
 * gcd - non-rec.
*/
int gcdNRec(int a, int b){
    if(b > a){
        int temp = b;
        b = a;
        a = temp;
    }
    while(b != 0){
        int c = a % b;
        a = b;
        b = c;
        
    }
    return a;

}


/**
 * Binomial coefficient - rec.
 * 背清楚遞迴表示式
 * 
*/
int binoRec(int n, int m){
    if(m==0){
        return 1;
    }
    else if(n==m){
        return 1;
    }else{
        return binoRec(n-1, m) + binoRec(n-1, m-1);
    }
}

/**
 * binomial coefficient - non-rec. - 完成約分思考
 * 
 * 原本思路: n! / (m! * (n-m)!)
 * 1. 根據定義拆成三個階乘，再做處理。
 * 2. 但是過程中可能產生overflow，所以需要做提前約分處理
 * 3. 約分處理: 
 * 第一步，先找出分母較大者k，為max(m, n-m)。
 * 第二步，削去過程，已知 k 比 n 小
 * 分子: n! = 1 * 2 * 3 * ..... * n
 * 消去: k! = 1 * 2 * 3 * ...* k
 * 削掉的部分為 1 ~ k 剩下部分為 (k+1) ~ n
 * 得到如下，設 a部分 為 n! / k! = (k+1) * (k+2) * ... * n
 * 
 * 整體得到， a部分 / (n-k)!
 * 設 b部分 為 (n-k)!
 * 
 * 
*/


int binoNRec(int n, int m){
    int a = 1, b = 1, k = std::max(m, n-m);
    // 計算a部分
    for(int i=(k+1);i<=n;i++){
        a = a * i;
    }
    // 計算b部分
    for(int i=1;i<=(n-k);i++){
        b = b * i;
    }
    return a / b;
}

/**
 * sum - rec.
*/
int sumRec(int n){
    if (n == 0){
        return 0;
    }else{
        return sumRec(n - 1) + n;
    }
}
/**
 * sum - non-rec.
*/
int sumNRec(int n){
    int sum = 0;
    for(int i = 1; i<=n;i++){
        sum = sum + i;
    }
    return sum;
}


/** #exp - rec.
*/
int expRec(int x, int y){
    if(y == 0){
        return 1;
    }else{
        return expRec(x, y-1) * x;
    }
}

int expNRec(int x, int y){
    int result = 1;
    for(int i=1;i<=y;i++){
        result = result * x;
    }
    return result;
}


/** #Fibonacci -rec.
*/
int fibRec(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibRec(n-1) + fibRec(n-2);
    }
}

int fibNRec(int n){
    // 初值 f1 = 0, f2 = 1 
    int a = 0, b = 1, c = 0;
    for(int i=2;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// factorial - rec.
int facRec(int n){
    if(n==0){
        return 1;
    }else{
        return facRec(n-1) * n;
    }
}

// factorial - non rec.
int facNRec(int n){
    int result = 1;
    for(int i=1;i<=n;i++){
        result = result * i;
    }
    return result;
}

int main(){
    /** #GCD Test
     * std::cout << gcdRec(9,12) << '\n';
     * >>> 3
     * 
     * std::cout << gcdNRec(9,12) << '\n';
     * >>> 3
     */


    /** #binomial test
     * std::cout << binoRec(5,2) << '\n';
     * >>> 10 
     * 
     * std::cout << binoNRec(5,2) << '\n';
     * >>> 10 
     */
    

    /** #sum test
     * std::cout << sumRec(3) << '\n';
     * >>> 6
     * 
     * std::cout << sumNRec(3) << '\n';
     * >>> 6
    */

   /** #exp test
    std::cout << expRec(3,5) << '\n';
    >>> 243o
    std::cout << expNRec(3,5) << '\n';
    >>> 243
   */

    /** #Fibonacci test 
    std::cout << fibRec(10) << '\n';
    >>> 55

    std::cout << fibNRec(10) << '\n';
    >>> 55
    */

    /** #Factorial test 
    std::cout << facRec(5) << '\n';
    std::cout << facNRec(5) << '\n';
    >>> 120 
     * 
    */

    return 0;
}