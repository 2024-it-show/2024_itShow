#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>

int main()
{
    // 메인 윈도우 생성
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML 게임");

    // 표시할 스프라이트 로드
    sf::Texture texture;
    if (!texture.loadFromFile("EndLetter.png"))
        return EXIT_FAILURE; // 텍스처 로드 실패 시 프로그램 종료
    sf::Sprite sprite(texture);

    // 스프라이트의 초기 위치 설정 및 크기 조정
    const float initialX = 400.0f;
    const float initialY = 300.0f;
    const float finalX = 633.0f;
    const float finalY = 330.0f;
    sprite.setPosition(initialX, initialY);
    sprite.setScale(0.25f, 0.25f);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

    bool end = true; // 스프라이트가 나타날 조건을 나타내는 변수
    sf::Clock clock; // 애니메이션 시간 관리를 위한 시계
    bool animationStarted = false; // 애니메이션 시작 여부를 나타내는 변수
    bool animationEnded = false; // 애니메이션 종료 여부를 나타내는 변수

    while (window.isOpen())
    {
        // 이벤트 처리
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close(); // 창이 닫히면 프로그램 종료
        }

        // 애니메이션 시작 조건 확인
        if (end && !animationStarted)
        {
            clock.restart(); // 애니메이션 시간을 다시 시작
            animationStarted = true; // 애니메이션 시작
        }

        // 화면 지우기
        window.clear();

        // 애니메이션이 시작된 경우, 반동 효과를 적용하여 스프라이트 위치 업데이트
        if (animationStarted && !animationEnded)
        {
            float time = clock.getElapsedTime().asSeconds(); // 경과 시간 가져오기
            if (time <= 5.0f) // 애니메이션이 5초 동안 지속됨
            {
                float bounce = std::sin(time * 10) * 10; // 반동 효과 적용 (주기와 진폭 조정 가능)
                sprite.setPosition(finalX, finalY + bounce); // 스프라이트의 위치를 반동에 맞게 설정
            }
            else
            {
                sprite.setPosition(finalX, finalY); // 애니메이션이 끝난 후 스프라이트 위치 고정
                animationEnded = true; // 애니메이션 종료 표시
            }
        }

        // 스프라이트 그리기
        window.draw(sprite);

        // 창 업데이트
        window.display();
    }

    return EXIT_SUCCESS;
}
