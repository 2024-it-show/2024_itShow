#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Animation");

    sf::Texture texture;
    if (!texture.loadFromFile("EndLetter.png")) {
        return -1;
    }

    sf::Sprite sprite(texture);
    sprite.setPosition(633, 330); // 초기 위치 설정
    sprite.setScale(0.25f, 0.25f);

    sf::Clock clock;
    bool animationComplete = false;
    bool bounceStarted = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float elapsedTime = clock.getElapsedTime().asSeconds();

        if (!animationComplete) {
            if (elapsedTime >= 0.2f && elapsedTime <= 0.7f) {
                // 스프라이트가 0.5초 동안 튕김
                float progress = (elapsedTime - 0.2f) / 0.5f;
                float bounce = 45 * (1 - progress); // 약 20픽셀 정도 튕김
                sprite.setPosition(633, 330 - bounce);
                bounceStarted = true;
            }
            else if (bounceStarted) {
                // 튕기는 애니메이션이 완료되면 최종 위치로 설정
                sprite.setPosition(633, 330);
                animationComplete = true;
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
