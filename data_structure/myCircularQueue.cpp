#include <iostream>
#include "myCircularQueue.hpp"

using namespace std;

int main() {
    // 배열 크기 4 -> 실제 저장 가능 데이터 3개 (한 칸은 비워둠)
    int arr_size = 4;
    MyCircularQueue q(arr_size);

    cout << "=== 1. 초기 데이터 삽입 (Push 3개) ===" << endl;
    try {
        q.push(10);
        q.push(20);
        q.push(30);
        cout << "현재 Size: " << q.get_size() << " / " << (q.get_max_size() - 1) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "\n=== 2. 가득 찼을 때 Push 테스트 (Overflow) ===" << endl;
    try {
        cout << "Push 40 시도..." << endl;
        q.push(40); // 여기서 에러가 나야 정상
    } catch (const exception& e) {
        cout << "[성공] 예외 발생: " << e.what() << endl;
    }

    cout << "\n=== 3. 데이터 삭제 후 공간 재활용 테스트 (핵심!) ===" << endl;
    try {
        cout << "Pop: " << q.pop() << endl; // 10 제거 (공간 1개 생김)
        cout << "Pop: " << q.pop() << endl; // 20 제거 (공간 1개 더 생김)
        cout << "현재 Size: " << q.get_size() << endl;

        cout << ">> 삭제된 자리에 새로운 데이터 Push 40, 50" << endl;
        q.push(40); // tail이 배열 끝을 찍고 0번 인덱스로 돌아와야 함
        q.push(50);
        
        cout << "현재 Size: " << q.get_size() << endl;
        
        // 데이터 순서 확인
        cout << "Pop(기대값 30): " << q.pop() << endl;
        cout << "Pop(기대값 40): " << q.pop() << endl;
        cout << "Pop(기대값 50): " << q.pop() << endl;

    } catch (const exception& e) {
        cout << "에러 발생: " << e.what() << endl;
    }

    cout << "\n=== 4. 비어있을 때 Pop 테스트 (Underflow) ===" << endl;
    try {
        q.pop();
    } catch (const exception& e) {
        cout << "[성공] 예외 발생: " << e.what() << endl;
    }

    return 0;
}
