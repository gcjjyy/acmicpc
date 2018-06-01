/*
문제
세 정수 A, B, C가 주어진다. 이 때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)

출력
두 번째로 큰 정수를 출력한다.
*/
#include <stdio.h>

int A, B, C;

int main() {
    scanf("%d %d %d", &A, &B, &C);

    if((A >= B && A <= C) || (A >= C && A <= B)) printf("%d\n", A);
    else if((B >= A && B <= C) || (B >= C && B <= A)) printf("%d\n", B);
    else if((C >= A && C <= B) || (C >= B && C <= A)) printf("%d\n", C);

    return 0;
}