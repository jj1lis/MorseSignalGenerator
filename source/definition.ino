#pragma once
const int DASH = 5;          //短点pinの定義。内臓プルアップ抵抗を有効にしているのでつなぎ方に注意。
const int DOT = 6;           //長点pinの定義。短点pinと注意点は同様。
const int SPEAKER = 3;        //スピーカーpinの定義。PWM出力のできるpinしか対応していないので注意。
const int TONE = 700;         //発生させる矩形波の周波数の定義。(単位:[Hz])旧日本軍なんかは800Hzを使用していた。
const int DELAY_TIME = 70;    //遅延時間の定義(単位:[ms])短点の音の長さの基準となる。

typedef enum{
    dot,
    dash,
    squeeze,
    none,
}InputType;
