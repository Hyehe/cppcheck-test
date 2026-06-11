#include <iostream>
#include <cstring>
#include <cstdlib>

// 1. 하드코딩된 IP 주소 (Semgrep 무료 규칙으로 탐지)
const char* SERVER_IP = "192.168.0.1";

// 2. gets() 함수 사용 - 버퍼 오버플로우 취약점
// (Semgrep이 gets는 위험하다고 경고)
void readInput() {
    char buffer[10];
    gets(buffer);  // gets는 입력 길이 체크 안 함 → 취약
}

// 3. strcpy() 사용 - 버퍼 오버플로우 취약점
void copyString() {
    char dest[10];
    char* src = (char*)"This is a very long string that will overflow";
    strcpy(dest, src);  // 길이 체크 없이 복사 → 취약
}

// 4. system() 함수로 외부 명령 실행 - 커맨드 인젝션 취약점
void runCommand(char* input) {
    char cmd[100];
    sprintf(cmd, "echo %s", input);
    system(cmd);  // 사용자 입력을 그대로 system()에 전달 → 위험
}

// 5. malloc 후 free 안 함 - 메모리 누수
void memoryLeak() {
    int* ptr = (int*)malloc(sizeof(int) * 100);
    ptr[0] = 42;
    // free(ptr); 없음 → 메모리 누수
}

int main() {
    readInput();
    copyString();
    memoryLeak();
    return 0;
}
#