#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>

int main()
{
    // ���� ������ ����
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML ����");

    // ǥ���� ��������Ʈ �ε�
    sf::Texture texture;
    if (!texture.loadFromFile("EndLetter.png"))
        return EXIT_FAILURE; // �ؽ�ó �ε� ���� �� ���α׷� ����
    sf::Sprite sprite(texture);

    // ��������Ʈ�� �ʱ� ��ġ ���� �� ũ�� ����
    const float initialX = 400.0f;
    const float initialY = 300.0f;
    const float finalX = 633.0f;
    const float finalY = 330.0f;
    sprite.setPosition(initialX, initialY);
    sprite.setScale(0.25f, 0.25f);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

    bool end = true; // ��������Ʈ�� ��Ÿ�� ������ ��Ÿ���� ����
    sf::Clock clock; // �ִϸ��̼� �ð� ������ ���� �ð�
    bool animationStarted = false; // �ִϸ��̼� ���� ���θ� ��Ÿ���� ����
    bool animationEnded = false; // �ִϸ��̼� ���� ���θ� ��Ÿ���� ����

    while (window.isOpen())
    {
        // �̺�Ʈ ó��
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close(); // â�� ������ ���α׷� ����
        }

        // �ִϸ��̼� ���� ���� Ȯ��
        if (end && !animationStarted)
        {
            clock.restart(); // �ִϸ��̼� �ð��� �ٽ� ����
            animationStarted = true; // �ִϸ��̼� ����
        }

        // ȭ�� �����
        window.clear();

        // �ִϸ��̼��� ���۵� ���, �ݵ� ȿ���� �����Ͽ� ��������Ʈ ��ġ ������Ʈ
        if (animationStarted && !animationEnded)
        {
            float time = clock.getElapsedTime().asSeconds(); // ��� �ð� ��������
            if (time <= 5.0f) // �ִϸ��̼��� 5�� ���� ���ӵ�
            {
                float bounce = std::sin(time * 10) * 10; // �ݵ� ȿ�� ���� (�ֱ�� ���� ���� ����)
                sprite.setPosition(finalX, finalY + bounce); // ��������Ʈ�� ��ġ�� �ݵ��� �°� ����
            }
            else
            {
                sprite.setPosition(finalX, finalY); // �ִϸ��̼��� ���� �� ��������Ʈ ��ġ ����
                animationEnded = true; // �ִϸ��̼� ���� ǥ��
            }
        }

        // ��������Ʈ �׸���
        window.draw(sprite);

        // â ������Ʈ
        window.display();
    }

    return EXIT_SUCCESS;
}
