# note

## namespace

### 什麼是 namespace?

一個變數名稱不可以重複宣告與使用，而 namespace 用來避免變數名稱的衝突問題，
如果我們想要重複使用，我們可以透過 namespace 來定義變數，
當我們使用變數時，需要同時提醒這個變數是在哪一個 namespace 當中的。

### 如何宣告 namespace?

格式如下

```c++
namespace first {
int x = 1;
}
```

### 如何使用 namespace 當中的變數?

### 第一個做法

在使用變數時，前方加入 namespace 名稱和兩個冒號。

ex. `<namespace 的名稱>::<變數名稱> => first::x = 1;`

### 第二個做法

在某個區域中宣告以下我們預設使用哪個 namespace，
這樣在那個 namespace 當中的變數我們就可以不用宣告，也不用在前面提示 namespace，預設就會使用該 namespace 的變數。
ex. using namespace first;

### 其他有趣的事情?和一些提醒?

像是宣告 string 型態，我們用 std::string，當中 std 就是一個 namespace，
還有 std::cout...等等。

儘管我們有時候可以透過 using namespace 省去麻煩，
但是我們希望提醒自己這些變數是從哪邊來的，
所以我們盡量不對這些系統變數使用 using namespace。

...

## 型態別名

### 摘要

1. 甚麼是型態別名?
2. 有哪些做法? | typedef、using
3. 差別是甚麼? | 推薦的作法

### 型態別名

型態別名是我們可以在程式中自行額外定義某個資料型別的名稱並重複使用。通常目的是為了避免 typo、避免過長型態，或是標示資料型態的用途等等。

### 有哪些做法?

可以使用 typedef 或是 using 這兩種 keyword

比較推薦使用 using，因為搭配 template 使用時會比較方便。

template 後面才會提到

### typedef 該怎麼使用?

格式為

```
typedef <type> <type_alias>
```

通常會在別名後面加上\_t 來表示這是我們建立的型態別名。

ex.

```c++
typedef int number_t;

number x = 3; //  x的型態會視為int

typedef std::string text_t
```

## 型態轉換

### 摘要

1. 型態有哪些方式轉換? | implicit、explicit
2. implicit 自動轉換的例子
3. explicit 手動轉換的例子

### implicit

implicit 為 c++中會將型態自動識別並強制轉換的機制。

有以下幾種情況

1. 指派小數給 int
2. 指派整數給 char
