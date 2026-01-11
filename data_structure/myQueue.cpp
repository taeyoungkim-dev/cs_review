#include <iostream>
#include "myQueue.hpp" // 작성하신 헤더 파일

using namespace std;

int main() {
    // 큐 생성 (크기 3)
    int q_size = 3;
    MyQueue q(q_size);

    cout << "=== 1. 데이터 삽입 테스트 (Push) ===" << endl;
    try {
        q.push(10);
        cout << "Push: 10 (Size: " << q.get_size() << ")" << endl;
        q.push(20);
        cout << "Push: 20 (Size: " << q.get_size() << ")" << endl;
        q.push(30);
        cout << "Push: 30 (Size: " << q.get_size() << ")" << endl;
    } catch (const exception& e) {
        cout << "에러 발생: " << e.what() << endl;
    }

    cout << "\n=== 2. 가득 찼을 때 삽입 테스트 (Overflow) ===" << endl;
    try {
        cout << "Push: 40 시도..." << endl;
        q.push(40); // 여기서 예외가 발생해야 함
    } catch (const exception& e) {
        cout << "[성공] 예외 정상 발생: " << e.what() << endl;
    }

    cout << "\n=== 3. 데이터 꺼내기 테스트 (Pop) ===" << endl;
    try {
        cout << "Pop: " << q.pop() << endl;
        cout << "Pop: " << q.pop() << endl;
        cout << "Pop: " << q.pop() << endl;
        cout << "현재 Size: " << q.get_size() << endl;
    } catch (const exception& e) {
        cout << "에러 발생: " << e.what() << endl;
    }

    cout << "\n=== 4. 비어있을 때 꺼내기 테스트 (Underflow) ===" << endl;
    try {
        cout << "Pop 시도..." << endl;
        q.pop(); // 여기서 예외가 발생해야 함
    } catch (const exception& e) {
        cout << "[성공] 예외 정상 발생: " << e.what() << endl;
    }

    cout << "\n=== 5. 선형 큐(Linear Queue)의 한계 확인 ===" << endl;
    // 현재 큐는 다 비워져서 size()는 0이지만, tail은 끝까지 갔기 때문에
    // 추가로 push를 하면 에러가 날 것입니다. (이것이 원형 큐가 필요한 이유)
    try {
        cout << "현재 큐는 비어있음(Size: " << q.get_size() << ")" << endl;
        cout << "하지만 tail이 끝에 도달했으므로 Push 50 시도..." << endl;
        q.push(50); 
    } catch (const exception& e) {
        cout << "[한계 확인] 큐가 비어있어도 공간 재사용 불가: " << e.what() << endl;
    }

    return 0;
}
