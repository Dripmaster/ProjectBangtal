// ProjectBangtal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Bangtal.h>
SceneID firstScene;
int main()
{
	firstScene = createScene("방1","Images/배경-1.png");
	startGame(firstScene);
}