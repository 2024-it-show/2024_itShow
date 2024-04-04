#include <SFML/Graphics.hpp> 
#include <iostream>

using namespace std;
using namespace sf;


int main()
{

    Font font;
    auto a = font.loadFromFile("설레임.ttf");

    RenderWindow app(VideoMode(1280, 720), "game");

    Texture back[20];
    back[0].loadFromFile("game-back.png");
    back[1].loadFromFile("Hch1.png");
    back[2].loadFromFile("Hch1-2.png");
    back[3].loadFromFile("HchB.png");
    back[4].loadFromFile("HchG.png");
    back[5].loadFromFile("Hch2.png");
    back[6].loadFromFile("Mch1.png");
    back[7].loadFromFile("Mch1-2.png");
    back[8].loadFromFile("Mch1B.png");
    back[9].loadFromFile("Mch1G.png");
    back[10].loadFromFile("Mch2.png");
    back[11].loadFromFile("Mch2B.png");
    back[12].loadFromFile("Mch2G.png");
    back[13].loadFromFile("Jch1.png");
    back[14].loadFromFile("JchB.png");
    back[15].loadFromFile("JchG.png");
    Sprite background[20];
    for (int i = 0; i < 20; i++) {
        background[i].setTexture(back[i]);
        background[i].setScale(0.25f, 0.25f);
    }

    bool Screen1 = true;
    bool Hch1 = false, Hch1_2 = false, HchB = false, HchG = false, Hch2 = false;
    bool Mch1 = false, Mch1_2 = false, Mch1B = false, Mch1G = false, Mch2 = false, Mch2B = false, Mch2G = false;
    bool Jch1 = false, JchG = false, JchB = false;
    Texture* block = new Texture[24];
    block[0].loadFromFile("1.png");
    block[1].loadFromFile("2.png");
    block[2].loadFromFile("3.png");
    block[3].loadFromFile("4.png");
    block[4].loadFromFile("5.png");
    block[5].loadFromFile("6.png");
    block[6].loadFromFile("7.png");
    block[7].loadFromFile("8.png");
    block[8].loadFromFile("9.png");
    block[9].loadFromFile("10.png");
    block[10].loadFromFile("11.png");
    block[11].loadFromFile("12.png");
    block[12].loadFromFile("13.png");
    block[13].loadFromFile("14.png");
    block[14].loadFromFile("15.png");
    block[15].loadFromFile("16.png");
    block[16].loadFromFile("17.png");
    block[17].loadFromFile("18.png");
    block[18].loadFromFile("19.png");
    block[19].loadFromFile("20.png");
    block[20].loadFromFile("21.png");
    block[21].loadFromFile("22.png");
    block[22].loadFromFile("23.png");
    block[23].loadFromFile("24.png");

    Sprite* button = new Sprite[24];

    for (int i = 0; i < 24; i++) {
        button[i].setTexture(block[i]);
        button[i].setScale(0.25f, 0.25f);
    }


    button[0].setPosition(958, 571);
    button[7].setPosition(210, 571);
    button[12].setPosition(210, 36);
    button[19].setPosition(958, 36);
    button[13].setPosition(321, 36);
    button[6].setPosition(321, 538);

    for (int i = 0; i < 5; i++) {
        button[1 + i].setPosition(852 - (i * 106), 538);
        button[14 + i].setPosition(428 + (i * 106), 36);
        if (i < 4) {
            button[11 - i].setPosition(210, 147 + (i * 106));
            button[20 + i].setPosition(924, 147 + (i * 106));
        }
    }



    Texture* blockhover = new Texture[24];
    blockhover[0].loadFromFile("1h.png");
    blockhover[1].loadFromFile("2h.png");
    blockhover[2].loadFromFile("3h.png");
    blockhover[3].loadFromFile("4h.png");
    blockhover[4].loadFromFile("5h.png");
    blockhover[5].loadFromFile("6h.png");
    blockhover[6].loadFromFile("7h.png");
    blockhover[7].loadFromFile("8h.png");
    blockhover[8].loadFromFile("9h.png");
    blockhover[9].loadFromFile("10h.png");
    blockhover[10].loadFromFile("11h.png");
    blockhover[11].loadFromFile("12h.png");
    blockhover[12].loadFromFile("13h.png");
    blockhover[13].loadFromFile("14h.png");
    blockhover[14].loadFromFile("15h.png");
    blockhover[15].loadFromFile("16h.png");
    blockhover[16].loadFromFile("17h.png");
    blockhover[17].loadFromFile("18h.png");
    blockhover[18].loadFromFile("19h.png");
    blockhover[19].loadFromFile("20h.png");
    blockhover[20].loadFromFile("21h.png");
    blockhover[21].loadFromFile("22h.png");
    blockhover[22].loadFromFile("23h.png");
    blockhover[23].loadFromFile("24h.png");

    // nextbutton
    Texture next[4];
    next[0].loadFromFile("popupNB.png");
    next[1].loadFromFile("chNB1.png");
    next[2].loadFromFile("chNB2.png");
    Sprite nextbutton[4];
    for (int i = 0; i < 4; i++) {
        nextbutton[i].setTexture(next[i]);
        nextbutton[i].setScale(0.25f, 0.25f);
    }
    nextbutton[0].setPosition(715, 431);
    nextbutton[1].setPosition(1155, 595);
    nextbutton[2].setPosition(1038, 580);
    Texture nextBhover[4];
    nextBhover[0].loadFromFile("popupNBH.png");
    nextBhover[1].loadFromFile("chNBH1.png");
    nextBhover[2].loadFromFile("chNBH2.png");

    // choice button
    Texture choice;
    choice.loadFromFile("chB.png");
    Sprite chbutton[2];
    for (int i = 0; i < 2; i++) {
        chbutton[i].setTexture(choice);
        chbutton[i].setScale(0.25f, 0.25f);
    }
    chbutton[0].setPosition(801, 153);
    chbutton[1].setPosition(801, 382);
    Texture chBhover;
    chBhover.loadFromFile("chBH.png");


    bool isButtonHovered = false;

    Texture speech;
    speech.loadFromFile("chSB.png");
    Sprite chSB;
    chSB.setTexture(speech);
    chSB.setScale(0.25f, 0.25f);
    chSB.setPosition(327, 120);

    Texture pop[4];
    pop[0].loadFromFile("pop1.png");
    pop[1].loadFromFile("pop2.png");
    pop[2].loadFromFile("pop3.png");
    pop[3].loadFromFile("pop4.png");
    Sprite PopUp[4];
    for (int i = 0; i < 4; i++) {
        PopUp[i].setTexture(pop[i]);
        PopUp[i].setScale(0.25f, 0.25f);
        PopUp[i].setPosition(396, 206);
    }

    bool popup1 = false, popup2 = false, popup3 = false, popup4 = false;
    Text text;
    text.setFont(font);
    // font는 sf::Font의 객체입니다.

    // 보여줄 문자열 세팅
    text.setString("안녕하세요");

    // 문자 사이즈 세팅
    text.setCharacterSize(24);
    text.setPosition(880, 206);
    // 포인트과 아니라 픽셀 단위입니다!

    // 색 설정
    text.setFillColor(sf::Color::Red);

    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            Vector2f mousePos = app.mapPixelToCoords(Mouse::getPosition(app));
            for (int i = 0; i < 24; i++) {
                if (button[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    button[i].setTexture(blockhover[i]);
                }
                else {
                    button[i].setTexture(block[i]);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (button[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 3 && Screen1) {
                            Screen1 = false;
                            Hch1 = true;
                        }
                        else if (i == 8 && Screen1) {
                            Screen1 = false;
                            Mch1 = true;
                        }
                        else if (i == 11 && Screen1) {
                            Screen1 = false;
                            Hch2 = true;
                        }
                        else if (i == 14 && Screen1) {
                            Screen1 = false;
                            Jch1 = true;
                        }
                        else if (i == 18 && Screen1) {
                            Screen1 = false;
                            Mch2 = true;
                        }
                        else if (i == 7 && Screen1) {
                            popup1 = true;
                        }
                        else if (i == 15 && Screen1) {
                            popup2 = true;
                        }
                        else if (i == 19 && Screen1) {
                            popup3 = true;
                        }
                        else if (i == 23 && Screen1) {
                            popup4 = true;
                        }
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                if (nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    nextbutton[i].setTexture(nextBhover[i]);
                }
                else {
                    nextbutton[i].setTexture(next[i]);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 1 && Hch1) {
                            Hch1 = false;
                            Hch1_2 = true;
                        }
                        else if (i == 1 && Mch1) {
                            Mch1 = false;
                            Mch1_2 = true;
                        }
                        else if (i == 2 && (HchB || HchG || Mch1G || Mch1B || Mch2G || Mch2B || JchB || JchG)) {
                            HchB = false, HchG = false;
                            Mch1G = false, Mch1B = false, Mch2G = false, Mch2B = false;
                            JchB = false, JchG = false;
                            Screen1 = true;
                        }
                        else if (i == 0 && Screen1) {
                            popup1 = false;
                            popup2 = false;
                            popup3 = false;
                            popup4 = false;
                        }
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                if (chbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    chbutton[i].setTexture(chBhover);
                }
                else {
                    chbutton[i].setTexture(choice);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (chbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 0 && (Hch1_2 || Hch2)) {
                            Hch1_2 = false;
                            Hch2 = false;
                            HchB = true;
                        }
                        else if (i == 1 && (Hch1_2 || Hch2)) {
                            Hch1_2 = false;
                            Hch2 = false;
                            HchG = true;
                        }
                        if (i == 0 && Mch1_2 || Mch2) {
                            if (Mch1_2) {
                                Mch1B = true;
                            }
                            else if (Mch2) {
                                Mch2B = true;
                            }
                            Mch1_2 = false;
                            Mch2 = false;
                        }
                        else if (i == 1 && (Mch1_2 || Mch2)) {
                            if (Mch1_2) {
                                Mch1G = true;
                            }
                            else if (Mch2) {
                                Mch2G = true;
                            }
                            Mch1_2 = false;
                            Mch2 = false;
                        }
                        if (i == 0 && Jch1) {
                            Jch1 = false;
                            JchB = true;
                        }
                        else if (i == 1 && (Jch1)) {
                            Jch1 = false;
                            JchG = true;
                        }
                    }
                }
            }
        }
        if (Screen1) {
            app.draw(background[0]);
            for (int i = 23; i >= 0; i--) {
                if (i == 20) continue;
                app.draw(button[i]);
            }
            app.draw(button[20]);
        }

        //Hch
        if (Hch1) {
            app.draw(background[1]);
        }
        else if (Hch2) {
            app.draw(background[5]);
        }
        else if (Hch1_2) {
            app.draw(background[2]);
        }
        else if (HchB) {
            app.draw(background[3]);
        }
        else if (HchG) {
            app.draw(background[4]);
        }

        //Mch
        if (Mch1) {
            app.draw(background[6]);
        }
        else if (Mch2) {
            app.draw(background[10]);
        }
        else if (Mch1_2) {
            app.draw(background[7]);
        }
        else if (Mch1B) {
            app.draw(background[8]);
        }
        else if (Mch1G) {
            app.draw(background[9]);
        }
        else if (Mch2B) {
            app.draw(background[11]);
        }
        else if (Mch2G) {
            app.draw(background[12]);
        }

        //Jch
        if (Jch1) {
            app.draw(background[13]);
            app.draw(text);
        }
        else if (JchB) {
            app.draw(background[14]);
        }
        else if (JchG) {
            app.draw(background[15]);
        }



        if (Hch1 || Mch1) {
            app.draw(nextbutton[1]);
        }
        if (Hch1_2 || Hch2 || Mch1_2 || Mch2 || Jch1) {
            app.draw(chbutton[0]);
            app.draw(chbutton[1]);
        }
        if (HchB || HchG || Mch1B || Mch1G || Mch2B || Mch2G || JchB || JchG) {
            app.draw(nextbutton[2]);
            app.draw(chSB);
        }

        if (popup1 || popup2 || popup3 || popup4) {

            if (popup1) {
                app.draw(PopUp[0]);
            }
            else if (popup2) {
                app.draw(PopUp[1]);
            }
            else if (popup3) {
                app.draw(PopUp[2]);
            }
            else if (popup4) {
                app.draw(PopUp[3]);
            }
            app.draw(nextbutton[0]);
        }
        app.display();
    }
    delete[] block;
    delete[] blockhover;
    delete[] button;

    return 0;
}