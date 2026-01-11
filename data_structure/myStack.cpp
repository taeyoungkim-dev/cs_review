#include <iostream>
#include <vector>
#include <chrono> // 시간을 재기 위한 헤더
#include <iomanip> // 소수점 출력을 위해 필요
#include "MyStack.hpp" // 작성하신 헤더 파일

using namespace std;
using namespace std::chrono;

// 성능 측정을 위한 타이머 클래스 (간단 버전)
class Timer {
    high_resolution_clock::time_point start_time;
public:
    Timer() { start_time = high_resolution_clock::now(); }
    double elapsed() {
        auto end_time = high_resolution_clock::now();
        return duration<double, milli>(end_time - start_time).count();
    }
};

int main() {
    // ==========================================
    // Part 1. 시각화 (동작 검증)
    // ==========================================
    cout << "\n[1] 스택 동작 시각화 테스트" << endl;
    cout << "---------------------------------" << endl;
    
    MyStack visualStack(5); // 크기 5

    // Push 과정 보여주기
    cout << ">> 데이터를 넣습니다 (Push):" << endl;
    for (int i = 1; i <= 3; i++) {
        int val = i * 10;
        visualStack.push(val);
        cout << "   [+] Push(" << val << ") \t-> 현재 tail 위치: " << visualStack.size() << endl;
    }

    cout << "\n>> 데이터를 뺍니다 (Pop):" << endl;
    // Pop 과정 보여주기
    while(visualStack.size() > 0) {
        int val = visualStack.pop();
        cout << "   [-] Pop() 결과: " << val << " \t-> 남은 데이터: " << visualStack.size() << endl;
    }


    // ==========================================
    // Part 2. 성능 비교 (Benchmark)
    // MyStack vs Raw Array (C스타일) vs std::vector
    // ==========================================
    cout << "\n\n[2] 성능 측정 (1,000,000회 연산)" << endl;
    cout << "---------------------------------" << endl;

    const int ITERATIONS = 1000000; // 100만 번

    // 1. MyStack 테스트
    {
        MyStack s(ITERATIONS);
        Timer t; // 시간 측정 시작
        
        for(int i=0; i<ITERATIONS; ++i) s.push(i);
        for(int i=0; i<ITERATIONS; ++i) s.pop();
        
        cout << "1. MyStack 소요 시간:    \t" << fixed << setprecision(2) << t.elapsed() << " ms" << endl;
    }

    // 2. Raw Array (일반 배열) 테스트
    // 가장 빠릅니다. (함수 호출 오버헤드가 없고, 경계 검사를 안 하기 때문)
    {
        int* arr = new int[ITERATIONS];
        int tail = 0;
        Timer t; // 시간 측정 시작

        // Push 흉내 (경계 검사 없이 바로 대입)
        for(int i=0; i<ITERATIONS; ++i) {
            arr[tail++] = i;
        }
        // Pop 흉내
        for(int i=0; i<ITERATIONS; ++i) {
            --tail;
            int val = arr[tail];
        }

        cout << "2. Raw Array (C배열) 시간:\t" << t.elapsed() << " ms (가장 빠름)" << endl;
        delete[] arr;
    }

    // 3. std::vector (C++ 표준) 테스트
    // 안전성과 편의성을 갖추고도 매우 빠릅니다.
    {
        vector<int> v;
        v.reserve(ITERATIONS); // 메모리 미리 확보 (공정한 비교를 위해)
        Timer t;

        for(int i=0; i<ITERATIONS; ++i) v.push_back(i);
        for(int i=0; i<ITERATIONS; ++i) v.pop_back();

        cout << "3. std::vector (표준) 시간:\t" << t.elapsed() << " ms" << endl;
    }

    cout << "\n>> 결론: 클래스로 감싸면 함수 호출 비용 때문에 Raw Array보다는 느리지만," << endl;
    cout << "         데이터 관리의 안전성(오버플로우 방지 등)을 얻을 수 있습니다." << endl;

    return 0;
}