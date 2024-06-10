#include <SFML/Graphics.hpp> 
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

int Number; // �ֻ��� ������ �����Դϴ�. 24�� �Ѿ�� 24�� ����� �ؿ�
int Jheart;
int Hheart;
int Mheart;
int Xheart;
int diceCount;
int Count;
bool Screen1;
bool Hch1, Hch1_2, HchB, HchG, Hch2;
bool Mch1, Mch1_2, Mch1B, Mch1G, Mch2, Mch2B, Mch2G, Mch;
bool Jch1, JchG, JchB, Jch2, Jch;
bool Hbasic1, Hbasic2, Jbasic1, Jbasic2, Mbasic1 , Mbasic2, Xbasic;
bool Ch13;
bool Ch13HMJ[3];
bool dice ;
bool showImage1;
bool rolling ;
bool popup1, popup2 , popup3, popup4;
bool chText ;
bool chSBTEXT;
bool Ch13B;
bool sB1;bool sB2; bool sB3;
bool rB1;
bool rB2;
bool rB3;
bool rB4;

bool rB_1;
bool rB_1_1;
bool rB_1_2;
bool rB_1_3;

bool rB_2;
bool rB_2_1 ;
bool rB_2_2;
bool rB_2_3 ;
bool end_chat, end_chatSec;
bool EndChSec, Endch , EndR;
bool EndLetter;
bool animationStarted ;
bool animationEnded ;
bool realEndBool;



const unsigned int originalWidth = 1280;
const unsigned int originalHeight = 720;

RenderWindow app(VideoMode(originalWidth, originalHeight), "game");


void resetGame() {
    Number = 19; // �ֻ��� ������ �����Դϴ�. 24�� �Ѿ�� 24�� ����� �ؿ�
    Jheart = 90;
    Hheart = 90;
    Mheart = 90;
    Xheart = 0;
    diceCount = 0;
    Screen1 = true;
    Hch1 = false, Hch1_2 = false, HchB = false, HchG = false, Hch2 = false;
    Mch1 = false, Mch1_2 = false, Mch1B = false, Mch1G = false, Mch2 = false, Mch2B = false, Mch2G = false, Mch = false;;
    Jch1 = false, JchG = false, JchB = false, Jch2 = false, Jch = false;
    Hbasic1 = false, Hbasic2 = false, Jbasic1 = false, Jbasic2 = false, Mbasic1 = false, Mbasic2 = false, Xbasic = false;
    Ch13 = false;
    Count = 0;
     dice = true;
     showImage1 = true;
     rolling = false;
     popup1 = false, popup2 = false, popup3 = false, popup4 = false;
     chText = false;
     chSBTEXT = false;
     Ch13B = false;
     sB1 = true, sB2 = false, sB3 = false;
     rB1 = false;
     rB2 = false;
     rB3 = false;
     rB4 = false;

     rB_1 = false;
     rB_1_1 = false;
     rB_1_2 = false;
     rB_1_3 = false;

     rB_2 = false;
     rB_2_1 = false;
     rB_2_2 = false;
     rB_2_3 = false;
     end_chat = false, end_chatSec = false;
     EndChSec = false, Endch = false, EndR = false;
     EndLetter = false;
     animationStarted = false;
     animationEnded = false;
    realEndBool = false;

    Ch13HMJ[0] = false;
    Ch13HMJ[1] = false;
    Ch13HMJ[2] = false;
}

int main()
{
    resetGame();

    Font font;
    auto a = font.loadFromFile("������.ttf");


    Texture back[30];
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
    back[16].loadFromFile("Jch2.png");
    back[17].loadFromFile("ch(13).png");
    back[18].loadFromFile("Hbasic2.png");
    back[19].loadFromFile("Hbasic1.png");
    back[20].loadFromFile("Jbasic1.png");
    back[21].loadFromFile("Jbasic2.png");
    back[22].loadFromFile("Mbasic1.png");
    back[23].loadFromFile("Mbasic2.png");
    back[24].loadFromFile("Xbasic.png");
    Sprite background[30];
    for (int i = 0; i < 30; i++) {
        background[i].setTexture(back[i]);
        background[i].setScale(0.25f, 0.25f);
    }
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

    //�ֻ��� ����
    Texture diceTextures[6];
    string filePath = "dice";
    for (int i = 0; i < 6; i++) {
        if (!diceTextures[i].loadFromFile(filePath + to_string(i + 1) + ".png")) {
            cerr << "Failed to load dice" << i + 1 << " texture!" << endl;
        }
    }

    // �ֻ��� ��������Ʈ ���� �� ����
    Sprite diceSprite; // �ֻ��� ������ ������ �ϴ� ���� 
    diceSprite.setScale(0.25f, 0.25f); //ũ�� 
    diceSprite.setPosition(580, 300);  //��ġ 

    // ���� �õ� �ʱ�ȭ
    srand(static_cast<unsigned int>(time(NULL)));
    Sprite dice1Sprite;
    Texture backgroundTexture1;
    if (!backgroundTexture1.loadFromFile("backdice.png")) {
        return EXIT_FAILURE;
    }


    vector<Texture> diceTextures1(6);
    for (int i = 0; i < 6; ++i) {
        if (!diceTextures1[i].loadFromFile("dice" + to_string(i + 1) + ".png")) {
            return EXIT_FAILURE;
        }
    }
    //��¥ 
    diceSprite.setScale(0.25f, 0.25f); //ũ�� 
    diceSprite.setPosition(580, 300);  //��ġ 
    diceSprite.setTexture(diceTextures[0]);
    int diceValue = 0;
    //�Ƹ� �̰� ��¥?
    dice1Sprite.setScale(0.25f, 0.25f); //ũ�� 
    dice1Sprite.setPosition(580, 300);  //��ġ 
    dice1Sprite.setTexture(diceTextures1[0]);
    int dice1Value = 1;

    srand(static_cast<unsigned>(std::time(nullptr)));

    Clock clock;

    float timeAccumulator = 0.0f;
    const float updateTime = 0.2f;
    const float totalRollingTime = 0.5f;
    Time elapsedTime;
    Clock clock1;
    Time delayTime = sf::seconds(0.5f);


    //�ֻ��� ��


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
    nextbutton[0].setPosition(811, 444);
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

    // popup
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
    

    Texture popBack;
    popBack.loadFromFile("pop-back.png");
    Sprite PopUpBack;
    PopUpBack.setTexture(popBack);
    PopUpBack.setScale(0.25f, 0.25f);


    //text
    Text text1, text2;
    text1.setFont(font);
    text2.setFont(font);
    text1.setString(L"�ȳ��ϼ���");
    text2.setString(L"�ȳ��ϼ���");
    text1.setCharacterSize(120);
    text2.setCharacterSize(120);
    text1.setScale(0.25f, 0.25f);
    text2.setScale(0.25f, 0.25f);
    text1.setFillColor(sf::Color(67, 64, 64));
    text2.setFillColor(sf::Color(67, 64, 64));

    Text chSBText;
    chSBText.setFont(font);
    chSBText.setString(L"�ȳ��ϼ���");
    chSBText.setCharacterSize(144);
    chSBText.setScale(0.25f, 0.25f);
    chSBText.setFillColor(sf::Color(67, 64, 64));

    // Ch13
    Texture choice13[3];
    choice13[0].loadFromFile("ch13H.png");
    choice13[1].loadFromFile("ch13M.png");
    choice13[2].loadFromFile("ch13J.png");
    Sprite chB13[3];
    for (int i = 0; i < 3; i++) {
        chB13[i].setTexture(choice13[i]);
        chB13[i].setScale(0.25f, 0.25f);
    }
    chB13[0].setPosition(516.57, 218);
    chB13[1].setPosition(832.14, 218);
    chB13[2].setPosition(201, 218);
    Texture chB13hover[3];
    chB13hover[0].loadFromFile("ch13HBh.png");
    chB13hover[1].loadFromFile("ch13MBh.png");
    chB13hover[2].loadFromFile("ch13JBh.png");


    Texture s_back[3]; // ���۹��
    s_back[0].loadFromFile("startB1.png");
    s_back[1].loadFromFile("startB2.png");
    s_back[2].loadFromFile("startB3.png");

    Sprite s_background[3];
    for (int i = 0; i < 3; i++) {
        s_background[i].setTexture(s_back[i]);
        s_background[i].setScale(0.25f, 0.25f);
    }


    Texture s_button[3]; // ���۹�ư
    s_button[0].loadFromFile("start1.png");
    s_button[1].loadFromFile("button1.png");

    Sprite s_nextbutton[2];
    for (int i = 0; i < 2; i++) {
        s_nextbutton[i].setTexture(s_button[i]);
        s_nextbutton[i].setScale(0.25f, 0.25f);
    }
    s_nextbutton[0].setPosition(535, 500);
    s_nextbutton[1].setPosition(950, 560);

    Texture s_buttonH[3]; // ���۹�ư ȣ��
    s_buttonH[0].loadFromFile("start2.png");
    s_buttonH[1].loadFromFile("button2.png");

    // ����
    Texture r_back[4];
    r_back[0].loadFromFile("Random1.png");
    r_back[1].loadFromFile("Random2.png");
    r_back[2].loadFromFile("Random3.png");
    r_back[3].loadFromFile("Random4.png");
    Sprite r_background[4];
    for (int i = 0; i < 4; i++) {
        r_background[i].setTexture(r_back[i]);
        r_background[i].setScale(0.25f, 0.25f);
    }

    Texture r_back_1[3]; // ���� �ι� ����
    r_back_1[0].loadFromFile("Random_UP_MJ.png");
    r_back_1[1].loadFromFile("Random_Up_JH.png");
    r_back_1[2].loadFromFile("Random_Up_HS.png");
    Sprite r_background_1[3];
    for (int i = 0; i < 3; i++) {
        r_background_1[i].setTexture(r_back_1[i]);
        r_background_1[i].setScale(0.25f, 0.25f);
    }

    Texture r_back_2[3]; // ���� �ι� ����
    r_back_2[0].loadFromFile("Random_Down_MJ.png");
    r_back_2[1].loadFromFile("Random_Down_JH.png");
    r_back_2[2].loadFromFile("Random_Down_HS.png");
    Sprite r_background_2[3];
    for (int i = 0; i < 3; i++) {
        r_background_2[i].setTexture(r_back_2[i]);
        r_background_2[i].setScale(0.25f, 0.25f);
    }


    // ������ �߰���


    // Click // �����μҸ� ���⼭ setPosition�� ���ָ� �Ǵµ� ĭ���� �ٸ��� ����� ��
    // �״ϱ� Number �ΰ� switch�� if�� 2���� 24����(for��X) ���� �༭ �Ǳ׸� ���� x,y ���ͼ� �����ϸ� �ſ� 
    Texture click[4];
    click[0].loadFromFile("click2~7.png");
    click[1].loadFromFile("click8~13.png");
    click[2].loadFromFile("click14~19.png");
    click[3].loadFromFile("click20~24.png");
    Sprite Click[4];
    for (int i = 0; i < 4; i++) {
        Click[i].setTexture(click[i]);
        Click[i].setScale(0.25f, 0.25f);
    }

    // ���� ȣ����
    Text JheartS;
    JheartS.setFont(font);
    JheartS.setCharacterSize(112);
    JheartS.setScale(0.25f, 0.25f);
    JheartS.setFillColor(sf::Color(255, 120, 135));
    JheartS.setPosition(130, 253);
    char buffer1[4]; // "%3d"�� �ִ� 3�ڸ����� ǥ���ϹǷ� 4�ڸ� �迭�� �ʿ���
    // �Ѽ� ȣ����
    Text HheartS;
    HheartS.setFont(font);
    HheartS.setCharacterSize(112);
    HheartS.setScale(0.25f, 0.25f);
    HheartS.setFillColor(sf::Color(103, 156, 68));
    HheartS.setPosition(1162, 253);
    char buffer2[4]; // "%3d"�� �ִ� 3�ڸ����� ǥ���ϹǷ� 4�ڸ� �迭�� �ʿ���
    // ���� ȣ����
    Text MheartS;
    MheartS.setFont(font);
    MheartS.setCharacterSize(112);
    MheartS.setScale(0.25f, 0.25f);
    MheartS.setFillColor(sf::Color(13, 85, 109));
    MheartS.setPosition(130, 550);
    char buffer3[4]; // "%3d"�� �ִ� 3�ڸ����� ǥ���ϹǷ� 4�ڸ� �迭�� �ʿ���
    // X ȣ����
    Text XheartS;
    XheartS.setFont(font);
    XheartS.setCharacterSize(112);
    XheartS.setScale(0.25f, 0.25f);
    XheartS.setFillColor(sf::Color(65, 58, 57));
    XheartS.setPosition(1162, 550);
    char buffer4[4]; // "%3d"�� �ִ� 3�ڸ����� ǥ���ϹǷ� 4�ڸ� �迭�� �ʿ���

    // EndChat
    // ��� �̹��� �ε�
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("ChatBack.png");
    Sprite backgroundSprite(backgroundTexture);

    // ���� �̹���
    vector<string> imageFilesM = { "Mchat1.png", "Mchat2.png", "Mchat3.png", "Mchat4.png", "Mchat5.png", "Mchat6.png", "Mchat7.png", "Mchat8.png","Mchat8.png" };
    vector<Texture> overlayTexturesM(imageFilesM.size());
    vector<Sprite> overlaySpritesM(imageFilesM.size());

    // �� �̹����� ũ��� ��ġ�� ������ ����
    vector<Vector2f> sizesM = { {269, 65}, {257, 63}, {313, 40}, {255, 40}, {296, 63}, {276, 40}, {292, 41}, {150, 41},{0,0} };
    vector<Vector2f> positionsM = { {446, 77}, {495, 155}, {495, 233}, {495, 288}, {495, 343}, {495, 421}, {495, 476}, {495, 532} ,{0,0} };

    // �������� �̹��� �ε�
    for (size_t i = 0; i < imageFilesM.size(); ++i)
    {
        if (!overlayTexturesM[i].loadFromFile(imageFilesM[i]))
        {
            return -1;
        }
        overlaySpritesM[i].setTexture(overlayTexturesM[i]);
        overlaySpritesM[i].setColor(Color(255, 255, 255, 0)); // ó������ ������ �����ϰ� ����

        // �� �������� �̹����� ũ��� ��ġ ����
        Vector2u textureSizeM = overlayTexturesM[i].getSize();
        overlaySpritesM[i].setScale(
            sizesM[i].x / textureSizeM.x,
            sizesM[i].y / textureSizeM.y
        ); // ������ ũ�� ����
        overlaySpritesM[i].setPosition(positionsM[i]); // ���Ϳ��� ��ġ ����
    }

    // Ÿ�̹��� ���� �ð�
    Clock clockM;
    float fadeDurationM = 2.0f; // �� ���̵� ���� ���� �ð� (�� ����)
    size_t currentImageIndexM = 0;

    // ���� �̹���
    vector<string> imageFilesJ = { "Jchat1.png", "Jchat2.png", "Jchat3.png", "Jchat4.png", "Jchat5.png", "Jchat6.png", "Jchat7.png", "Jchat8.png","Jchat8.png" };
    vector<Texture> overlayTexturesJ(imageFilesJ.size());
    vector<Sprite> overlaySpritesJ(imageFilesJ.size());

    // �� �̹����� ũ��� ��ġ�� ������ ����
    vector<Vector2f> sizesJ = { {306, 52}, {282, 63}, {234, 63}, {290, 40}, {282, 40}, {279, 63}, {274, 63}, {137, 41},{0,0} };
    vector<Vector2f> positionsJ = { {446, 86}, {495, 138}, {495, 216}, {495, 294}, {495, 349}, {495, 404}, {495, 482}, {495, 560},{0,0} };

    // �������� �̹��� �ε�
    for (size_t i = 0; i < imageFilesJ.size(); ++i)
    {
        if (!overlayTexturesJ[i].loadFromFile(imageFilesJ[i]))
        {
            return -1;
        }
        overlaySpritesJ[i].setTexture(overlayTexturesJ[i]);
        overlaySpritesJ[i].setColor(Color(255, 255, 255, 0)); // ó������ ������ �����ϰ� ����

        // �� �������� �̹����� ũ��� ��ġ ����
        Vector2u textureSizeJ = overlayTexturesJ[i].getSize();
        overlaySpritesJ[i].setScale(
            sizesJ[i].x / textureSizeJ.x,
            sizesJ[i].y / textureSizeJ.y
        ); // ������ ũ�� ����
        overlaySpritesJ[i].setPosition(positionsJ[i]); // ���Ϳ��� ��ġ ����
    }

    // Ÿ�̹��� ���� �ð�
    Clock clockJ;
    float fadeDurationJ = 2.0f; // �� ���̵� ���� ���� �ð� (�� ����)
    size_t currentImageIndexJ = 0;

    // �Ѽ� �̹���
    vector<string> imageFilesH = { "Hchat1.png", "Hchat2.png", "Hchat3.png", "Hchat4.png", "Hchat5.png", "Hchat6.png", "Hchat7.png", "Hchat8.png","Hchat8.png" };
    vector<Texture> overlayTexturesH(imageFilesH.size());
    vector<Sprite> overlaySpritesH(imageFilesH.size());

    vector<Vector2f> sizesH = { {300, 65}, {310, 40}, {231, 40}, {279, 63}, {265, 40}, {251, 63}, {323, 40}, {195, 41},{0,0} };
    vector<Vector2f> positionsH = { {446, 77}, {495, 155}, {495, 210}, {495, 265}, {495, 343}, {495, 398}, {495, 476}, {495, 531},{0,0} };

    for (size_t i = 0; i < imageFilesH.size(); ++i)
    {
        if (!overlayTexturesH[i].loadFromFile(imageFilesH[i]))
        {
            return -1;
        }
        overlaySpritesH[i].setTexture(overlayTexturesH[i]);
        overlaySpritesH[i].setColor(Color(255, 255, 255, 0));

        Vector2u textureSizeH = overlayTexturesH[i].getSize();
        overlaySpritesH[i].setScale(
            sizesH[i].x / textureSizeH.x,
            sizesH[i].y / textureSizeH.y
        );
        overlaySpritesH[i].setPosition(positionsH[i]);
    }


    // Ÿ�̹��� ���� �ð�
    Clock clockH;
    float fadeDurationH = 2.0f; // �� ���̵� ���� ���� �ð� (�� ����)
    size_t currentImageIndexH = 0;

    // X �̹���
    vector<string> imageFilesX = { "Xchat1.png", "Xchat2.png", "Xchat3.png", "Xchat4.png", "Xchat5.png", "Xchat6.png", "Xchat7.png", "Xchat8.png", "Xchat8.png"};
    vector<Texture> overlayTexturesX(imageFilesX.size());
    vector<Sprite> overlaySpritesX(imageFilesX.size());

    std::vector<sf::Vector2f> sizesX = { {308, 52}, {236, 59}, {265, 63}, {207, 63}, {242, 63}, {220, 63}, {269, 40}, {129, 41} ,{0,0} };
    std::vector<sf::Vector2f> positionsX = { {446, 86}, {495, 143}, {495, 217}, {495, 299}, {495, 377}, {495, 455}, {495, 533}, {495, 588},{0,0} };


    for (size_t i = 0; i < imageFilesX.size(); ++i)
    {
        if (!overlayTexturesX[i].loadFromFile(imageFilesX[i]))
        {
            return -1;
        }
        overlaySpritesX[i].setTexture(overlayTexturesX[i]);
        overlaySpritesX[i].setColor(Color(255, 255, 255, 0));

        Vector2u textureSizeX = overlayTexturesX[i].getSize();
        overlaySpritesX[i].setScale(
            sizesX[i].x / textureSizeX.x,
            sizesX[i].y / textureSizeX.y
        );
        overlaySpritesX[i].setPosition(positionsX[i]);
    }


    // Ÿ�̹��� ���� �ð�
    Clock clockX;
    float fadeDurationX = 2.0f; // �� ���̵� ���� ���� �ð� (�� ����)
    size_t currentImageIndexX = 0;

    // chat ����

    // �������

    // ����

    Texture EndLT;
    EndLT.loadFromFile("EndLetter.png");
    Sprite EndL;
    EndL.setTexture(EndLT);
    const float initialX = 400.0f;
    const float initialY = 300.0f;
    const float finalX = 633.0f;
    const float finalY = 330.0f;
    EndL.setPosition(initialX, initialY);
    EndL.setScale(0.25f, 0.25f);
    EndL.setOrigin(EndL.getGlobalBounds().width / 2, EndL.getGlobalBounds().height / 2);
    sf::Clock clock2; // �ִϸ��̼� �ð� ������ ���� �ð�

    Texture EndLH;
    EndLH.loadFromFile("EndLetterH.png");

    Texture EndBack;
    Sprite EndBackS;
    EndBack.loadFromFile("EndBackCh.png");
    EndBackS.setTexture(EndBack);
    EndBackS.setScale(0.25f, 0.25f);
    Texture EndBackArr[5];

    EndBackArr[0].loadFromFile("EndJ.png");
    EndBackArr[1].loadFromFile("EndM.png");
    EndBackArr[2].loadFromFile("EndH.png");
    EndBackArr[3].loadFromFile("EndX.png");
    Sprite EndBackSArr[5];
    for (int i = 0; i < 4; i++) {
        EndBackSArr[i].setTexture(EndBackArr[i]);
        EndBackSArr[i].setScale(0.25f, 0.25f);
    }


    Texture realEndT;
    realEndT.loadFromFile("realEndButton.png");
    Sprite realEnd;
    realEnd.setTexture(realEndT);
    realEnd.setScale(0.25f, 0.25f);
    realEnd.setPosition(1095, 69);
    Texture realEndH;
    realEndH.loadFromFile("realEndButtonH.png");

    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            else if (event.type == sf::Event::Resized)
            {
                float aspectRatio = static_cast<float>(originalWidth) / originalHeight;
                unsigned int newHeight = event.size.height;
                unsigned int newWidth = static_cast<unsigned int>(newHeight * aspectRatio);
                app.setSize(sf::Vector2u(newWidth, newHeight));
                sf::Vector2u windowSize = app.getSize();
                sf::Vector2i newPosition((static_cast<int>(sf::VideoMode::getDesktopMode().width) - static_cast<int>(windowSize.x)) / 2, 0); // ȭ���� ��� ��ǥ�� ����Ͽ� Y ��ǥ�� 0���� ����
                app.setPosition(newPosition);
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && Screen1 && dice == true) {
                rolling = true;
                clock.restart(); // Restart the clock when space is pressed
                timeAccumulator = 0.0f;
            }

            if (Screen1 && dice == true)
                dice1Sprite.setTexture(backgroundTexture1);
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && Screen1 && dice == true) {
                //��¥ �ֻ��� ������
                int diceValue = rand() % 6;
                Number += diceValue + 1;
                Count++;
                if (Number > 24) Number -= 24;
                cout << "Dice value: " << diceValue + 1 << endl;        //�ֻ��� ���� ���Դϴ�
                cout << "Dice Num: " << Number << std::endl;       //�ֻ��� ���� ���Դϴ�
                cout << "count: " << Count << std::endl;

                // �ֻ��� ���� ���� ��������Ʈ ����
                diceSprite.setTexture(diceTextures[diceValue]);
                clock1.restart();
                dice = false;  // �ֻ��� ���� �� �ְ� �ϴ� �����Դϴ�! ���� �ٸ� �ڵ尡 ���� �� �ֻ����� �������� �ʴ´ٸ�  dice = true;�� �߰��ϸ� �ɰſ���..!
            }
            //�ֻ��� ��


            Vector2f mousePos = app.mapPixelToCoords(Mouse::getPosition(app));
            //�ֻ��� ��
            for (int i = 0; i < 2; i++) {
                if (s_nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isButtonHovered = true;
                }
                else {
                    isButtonHovered = false;
                }

                if (isButtonHovered) {
                    s_nextbutton[i].setTexture(s_buttonH[i]);
                }
                else {
                    s_nextbutton[i].setTexture(s_button[i]);
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (s_nextbutton[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 0 && sB1) {
                            sB1 = false;
                            sB2 = true;
                        }
                        else if (i == 1 && sB2) {
                            sB2 = false;
                            sB3 = true;
                        }
                    }
                }
            }

            for (int i = 1; i < 24; i++) {
                if (Number - 1 == i) {
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
                }

                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (button[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (i == 3 && Screen1 && Number == 4 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Screen1 = false;
                            Hch1 = true;
                            diceCount = Count + 1;
                        }
                        else if (i == 2 && Screen1 && Number == 3 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Mbasic1 = true;
                            Screen1 = false;
                            Mheart -= 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 4 && Screen1 && Number == 5 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Jbasic1 = true;
                            Screen1 = false;
                            Jheart += 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 6 && Screen1 && Number == 7 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Hbasic1 = true;
                            Screen1 = false;
                            Hheart -= 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 8 && Screen1 && Number == 9 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Screen1 = false;
                            Mch1 = true;
                            Mheart += 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 11 && Screen1 && Number == 12 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Screen1 = false;
                            Hch2 = true;
                            text1.setString(L"�� ī��� ���� �����ؿ�");
                            text1.setPosition(862, 225);
                            text2.setString(L"�� ��Ʈ���� ���� �����ؿ�");
                            text2.setPosition(848, 452);
                            diceCount = Count + 1;
                        }
                        else if (i == 14 && Screen1 && Number == 15 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Screen1 = false;
                            Jch1 = true;
                            text1.setString(L"���µ� 10�� ���� �ɸ��ϱ�\n���� �����߰ڳ׿�");
                            text1.setPosition(845, 206);
                            text2.setString(L"���� õõ�� ���� �����ƿ�");
                            text2.setPosition(848, 452);
                            diceCount = Count + 1;
                        }
                        else if (i == 17 && Screen1 && Number == 18 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Hbasic2 = true;
                            Screen1 = false;
                            Hheart += 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 18 && Screen1 && Number == 19 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Screen1 = false;
                            Mch2 = true;
                            text1.setString(L"(�峭������) ����\n�̷��� �׸��μ̱���");
                            text1.setPosition(882, 206);
                            text2.setString(L"�׷��� ���Ͻó׿�\n���� ���� ���!");
                            text2.setPosition(896, 433);
                            diceCount = Count + 1;
                        }
                        else if (i == 20 && Screen1 && Number == 21 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Jch2 = true;
                            Screen1 = false;
                            text1.setString(L"�ƴ�, ���� �ľ����");
                            text1.setPosition(888, 226);
                            text2.setString(L"���� �����ƿ�~\n������ �尩 �� �ǵ���");
                            text2.setPosition(875, 432);
                            diceCount = Count + 1;
                        }
                        else if (i == 12 && Screen1 && Number == 13 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Ch13 = true;
                            diceCount = Count + 1;
                        }
                        else if (i == 7 && Screen1 && Number == 8 && (diceCount != Count + 1)) {
                            dice = false;
                            showImage1 = true;
                            popup1 = true;
                            Hheart -= 10;
                            Jheart -= 10;
                            Mheart -= 10;
                            diceCount = Count + 1;
                        }
                        else if (i == 10 && Screen1 && Number == 11 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Jbasic2 = true;
                            Screen1 = false;
                            Jheart -= 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 15 && Screen1 && Number == 16 && (diceCount != Count + 1)) {
                            dice = false;
                            showImage1 = true;
                            popup2 = true;
                            Hheart += 15;
                            Jheart += 15;
                            Mheart += 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 19 && Screen1 && Number == 20 && (diceCount != Count + 1)) {
                            dice = false;
                            showImage1 = true;
                            popup3 = true;
                            Xheart += 20;
                            diceCount = Count + 1;
                        }
                        else if (i == 22 && Screen1 && Number == 23 && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Mbasic2 = true;
                            Screen1 = false;
                            Mheart += 15;
                            diceCount = Count + 1;
                        }
                        else if (i == 23 && Screen1 && Number == 24 && (diceCount != Count + 1)) {
                            dice = false;
                            showImage1 = true;
                            popup4 = true;
                            Hheart -= 15;
                            Jheart -= 15;
                            Mheart -= 15;
                            diceCount = Count + 1;
                        }
                        else if ((i == 13 || i == 1) && Screen1 && (Number == 2 || Number == 14) && (diceCount != Count + 1)) {
                            showImage1 = true;
                            Xbasic = true;
                            Screen1 = false;
                            Xheart += 15;
                            diceCount =Count + 1;
                        }
                        else if ((i == 5 || i == 9 || i == 16 || i == 21) && Screen1 && (Number == 6 || Number == 10 || Number == 17 || Number == 22) && (diceCount != Count + 1)) {
                            showImage1 = true;
                            diceCount = Count + 1;
                            int random = (int)(rand() % 4) + 1; // 1~4
                            if (random == 1) {
                                rB1 = true;
                                Hheart += 15;
                                Jheart += 15;
                                Mheart += 15;
                                Xheart += 15;
                            }
                            else if (random == 2) {
                                rB2 = true;
                                rB_1 = true;
                            }
                            else if (random == 3) {
                                rB3 = true;
                                rB_2 = true;
                            }
                            else if (random == 4) {
                                rB4 = true;
                                Xheart += 10;
                            }
                            Screen1 = false;
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
                        if (i == 2 && EndLetter) {
                            EndChSec = true; Endch = false;
                        }
                        if (i == 1 && Hch1) {
                            Hch1 = false;
                            Hch1_2 = true;
                            text1.setString(L"�̰� ��̾�������\n���� �ٸ� �� �����? ");
                            text1.setPosition(880, 206);
                            text2.setString(L"�׷��� �̹� �����ߴµ�\n�׳� �����? ");
                            text2.setPosition(865, 433);
                        }
                        else if (i == 1 && Mch1) {
                            Mch1 = false;
                            Mch1_2 = true;
                            text1.setString(L"��ġ�� �� ����������?\n���� ���~");
                            text1.setPosition(870, 206);
                            text2.setString(L"Ȥ�� �ֹ���\n�߸� ������?");
                            text2.setPosition(901, 433);
                        }
                        else if (i == 2 && (HchB || HchG || Mch1G || Mch1B || Mch2G || Mch2B || JchB || JchG || Ch13 || Hbasic1 || Hbasic2
                            || Jbasic1 || Jbasic2 || Mbasic1 || Mbasic2 || Xbasic || sB3 || rB1 || rB2 || rB3 || rB4
                            || rB_1_1 || rB_1_2 || rB_1_3 || rB_2_1 || rB_2_2 || rB_2_3)) {
                            HchB = false, HchG = false;
                            Mch1G = false, Mch1B = false, Mch2G = false, Mch2B = false;
                            JchB = false, JchG = false;
                            if (Ch13) {
                                if (Ch13HMJ[0]) {
                                    Hheart += 15;
                                }
                                else if (Ch13HMJ[1] && !Mch1_2) {
                                    Mheart += 15;
                                }
                                else if (Ch13HMJ[2]) {
                                    Jheart += 15;
                                }
                            }
                            for (int j = 0; j < 3; j++) Ch13HMJ[j] = false;
                            Ch13 = false; chSBTEXT = false;
                            Hbasic1 = false; Hbasic2 = false;
                            Jbasic1 = false; Jbasic2 = false;
                            Mbasic1 = false; Mbasic2 = false;
                            Xbasic = false;
                            rB1 = false; rB4 = false;
                            sB3 = false;
                            rB_1_1 = false; rB_1_2 = false; rB_1_3 = false; rB_2_1 = false; rB_2_2 = false; rB_2_3 = false;
                            Screen1 = true;

                            if (rB2) {
                                int random1 = (int)(rand() % 3) + 1; // 1~3
                                rB2 = false;
                                if (random1 == 1) { Mheart -= 10; rB_1_1 = true; }
                                else if (random1 == 2) { rB_1_2 = true; Jheart -= 10; }
                                else if (random1 == 3) { rB_1_3 = true; Hheart = 10; }
                                rB_1 = false;
                            }
                            else if (rB3) {
                                int random2 = (int)(rand() % 3) + 1; // 1~3
                                rB3 = false;
                                if (random2 == 1) {
                                    rB_2_1 = true; Mheart += 10;
                                }
                                else if (random2 == 2) { rB_2_2 = true; Jheart += 10; }
                                else if (random2 == 3) { rB_2_3 = true; Hheart += 10; }
                                rB_2 = false;
                            }
                        }
                        else if (i == 0 && Screen1) {
                            popup1 = false;
                            popup2 = false;
                            popup3 = false;
                            popup4 = false;
                        }
                        // endChat �߰�
                        else if (i==2&&end_chat) {
                            end_chatSec = true;
                            EndLetter = false;
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
                            if (Hch2) {
                                chSBText.setString(L"�� ī�����\n     ����...");
                                chSBText.setPosition(397, 192);
                            }
                            if (Hch1_2) {
                                chSBText.setString(L"( ��.. �޴밡 ���� )");
                                chSBText.setPosition(343, 213.99);
                            }
                            Hheart -= 20;
                            chText = false;
                            Hch1_2 = false;
                            Hch2 = false;
                            HchB = true;
                        }
                        else if (i == 1 && (Hch1_2 || Hch2)) {
                            if (Hch2) {
                                chSBText.setString(L"���� ����\n�����ؿ�!");
                                chSBText.setPosition(412, 192);
                            }
                            if (Hch1_2) {
                                chSBText.setString(L"\t\t���ƿ�!\n(�޴��ִ�!����)");
                                chSBText.setPosition(370, 193);
                            }
                            Hheart += 20;
                            chText = false;
                            Hch1_2 = false;
                            Hch2 = false;
                            HchG = true;
                        }
                        if (i == 0 && (Mch1_2 || Mch)) {
                            if (Mch1_2) {
                                chSBText.setString(L"  ( ���� ����\n�������̶�..)");
                                chSBText.setPosition(379, 187.99);
                                Mch1B = true;
                            }
                            else if (Mch2) {
                                chSBText.setString(L"\t�λ� ������\n�� �ȵǳ׿� ����;");
                                chSBText.setPosition(360, 187.99);
                                Mch2B = true;
                            }
                            Mheart -= 20;
                            chText = false;
                            Mch1_2 = false;
                            Mch2 = false;
                            Mch = false;
                        }
                        else if (i == 1 && (Mch1_2 || Mch)) {
                            if (Mch1_2) {
                                chSBText.setString(L"( ���� ���ǰ�\n   �ٸ����� )");
                                chSBText.setPosition(386, 187.99);
                                Mch1G = true;
                            }
                            else if (Mch2) {
                                chSBText.setString(L"���� �Ƴ��\n  ������");
                                chSBText.setPosition(397, 187.99);
                                Mch2G = true;
                            }
                            Mheart += 20;
                            chText = false;
                            Mch1_2 = false;
                            Mch2 = false;
                            Mch = false;
                        }
                        if (i == 0 && (Jch1 || Jch)) {
                            if (Jch1) {
                                chSBText.setString(L"   ��... �ǰ�\nĮ�����ó׿�");
                                chSBText.setPosition(385, 187.99);
                            }
                            else if (Jch) {
                                chSBText.setString(L"( �� ������\n������� ? )");
                                chSBText.setPosition(395, 191);
                            }
                            Jheart -= 20;
                            chText = false;
                            Jch1 = false;
                            Jch2 = false;
                            JchB = true;
                            Jch = false;
                        }
                        else if (i == 1 && (Jch1 || Jch)) {
                            if (Jch1) {
                                chSBText.setString(L"( �����ӳ�\n  ���־�!)");
                                chSBText.setPosition(406, 193);
                            }
                            else if (Jch) {
                                chSBText.setString(L"( ������ ����\n\t  ����!)");
                                chSBText.setPosition(386, 198);
                            }
                            Jheart += 20;
                            chText = false;
                            Jch1 = false;
                            Jch2 = false;
                            JchG = true;
                            Jch = false;
                        }
                    }
                }
            }
            for (int i = 0; i < 3; i++) {
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    if (chB13[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) && !EndChSec) {
                        Ch13B = true;
                        for (int j = 0; j < 3; j++) {
                            if (i == j) {
                                chB13[j].setTexture(chB13hover[j]);
                                Ch13HMJ[j] = true;
                            }
                            else {
                                chB13[j].setTexture(choice13[j]);
                                Ch13HMJ[j] = false;
                            }
                        }
                    }
                    if (!Ch13B) chB13[i].setTexture(choice13[i]);
                }
            }
            if (EndL.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                isButtonHovered = true;
            }
            else {
                isButtonHovered = false;
            }
            if (isButtonHovered) {
                EndL.setTexture(EndLH);
            }
            else {
                EndL.setTexture(EndLT);
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if ((EndL.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))) {
                    if (Screen1 && Count == 13) {
                        Screen1 = false;
                        EndR = false;
                        EndLetter = true;
                    }
                }
            }

            if (realEnd.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                isButtonHovered = true;
            }
            else {
                isButtonHovered = false;
            }
            if (isButtonHovered) {
                realEnd.setTexture(realEndH);
            }
            else {
                realEnd.setTexture(realEndT);
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                if ((realEnd.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))) {
                    if (realEndBool) {
                        resetGame();
                    }
                }
            }
        }

        if (Number == 1 && Count != 0) Number += 1;

        //�ֻ��� ���� 
        if (rolling && Count != 13) {
            elapsedTime = clock.getElapsedTime();
            timeAccumulator += elapsedTime.asSeconds();
            if (timeAccumulator >= updateTime) {
                timeAccumulator = 0.0f;
                int randomDice = rand() % 6;
                dice1Sprite.setTexture(diceTextures1[randomDice]);
                dice1Value = randomDice + 1;
            }

            if (elapsedTime.asSeconds() >= totalRollingTime) {
                rolling = false;
                showImage1 = false;
            }
        }

        //�ֻ��� ��
        std::snprintf(buffer1, sizeof(buffer1), "%3d", Jheart);
        JheartS.setString(buffer1);
        std::snprintf(buffer2, sizeof(buffer2), "%3d", Hheart);
        HheartS.setString(buffer2);
        std::snprintf(buffer3, sizeof(buffer3), "%3d", Mheart);
        MheartS.setString(buffer3);
        std::snprintf(buffer4, sizeof(buffer4), "%3d", Xheart);
        XheartS.setString(buffer4);

        // scree1
        if (Screen1) {
            app.draw(background[0]);
            for (int i = 23; i >= 0; i--) {
                if (i == 20) continue;
                app.draw(button[i]);
            }//�ֻ���
            if (showImage1) {
                app.draw(dice1Sprite);
            }
            else {
                app.draw(diceSprite);
            }
            app.draw(button[20]);
            app.draw(JheartS);
            app.draw(HheartS);
            app.draw(MheartS);
            app.draw(XheartS);
            for (int i = 0; i < 3; i++) chB13[i].setTexture(choice13[i]);
        }

        //����

        if (((Jheart >= 70 && Hheart >= 70) || (Jheart >= 70 && Mheart >= 70) || (Mheart >= 70 && Hheart >= 70)
            || (Mheart >= 70 && Hheart >= 70 && Jheart >= 70)) && EndLetter && !EndChSec) {
            app.draw(EndBackS);
            Endch = true;
        }


        if (Count == 13 && Screen1) {
            EndR = true;
            dice = false;
        }

        if (EndR && !animationStarted)
        {
            clock2.restart(); // �ִϸ��̼� �ð��� �ٽ� ����
            animationStarted = true; // �ִϸ��̼� ����
        }

        if (animationStarted && !animationEnded)
        {
            float time = clock2.getElapsedTime().asSeconds(); // ��� �ð� ��������
            if (time <= 15.0f) // �ִϸ��̼��� 5�� ���� ���ӵ�
            {
                float bounce = std::sin(time * 10) * 10; // �ݵ� ȿ�� ���� (�ֱ�� ���� ���� ����)
                EndL.setPosition(finalX, finalY + bounce); // ��������Ʈ�� ��ġ�� �ݵ��� �°� ����
            }
            else
            {
                EndL.setPosition(finalX, finalY); // �ִϸ��̼��� ���� �� ��������Ʈ ��ġ ����
                animationEnded = true; // �ִϸ��̼� ���� ǥ��
            }
        }

        if (EndR) {
            app.draw(EndL);
            for (int i = 0; i < 3; i++) chB13[i].setTexture(choice13[i]);
        }

        if (Endch) {
            app.draw(nextbutton[2]);
            if (Mheart >= 70 && Hheart >= 70 && Jheart >= 70) {
                chB13[0].setPosition(516.57, 218);
                chB13[1].setPosition(832.14, 218);
                chB13[2].setPosition(201, 218);
                for (int i = 0; i < 3; i++)   app.draw(chB13[i]);
            }
            else if (Jheart >= 70 && Mheart >= 70) {
                chB13[2].setPosition(358, 218);
                chB13[1].setPosition(673.57, 218);
                app.draw(chB13[1]);
                app.draw(chB13[2]);
            }
            else if (Mheart >= 70 && Hheart >= 70) {
                chB13[0].setPosition(358, 218);
                chB13[1].setPosition(673.57, 218);
                app.draw(chB13[0]);
                app.draw(chB13[1]);
            }
            else if (Jheart >= 70 && Hheart >= 70) {
                chB13[0].setPosition(358, 218);
                chB13[1].setPosition(673.57, 218);
                app.draw(chB13[0]);
                app.draw(chB13[1]);
            }
        }

        // chat �߰�
        if (((Mheart >= 70 && Jheart < 70 && Hheart < 70 && EndLetter) || (Mheart >= 70 && Ch13HMJ[1] && EndChSec)) && Count == 13) {
            Screen1 = false;
            float elapsedTimeM = clockM.getElapsedTime().asSeconds();

            if (currentImageIndexM < overlaySpritesM.size())
            {
                // ��� �ð��� ������� ���� ���� �� ���
                float alphaM = min(255.0f, (elapsedTimeM / fadeDurationM) * 255.0f);
                overlaySpritesM[currentImageIndexM].setColor(Color(255, 255, 255, static_cast<Uint8>(alphaM)));

                if (alphaM >= 255.0f)
                {
                    // ���� �̹����� ������ ���̵� �� �� �� ���� �̹����� �̵�
                    currentImageIndexM++;
                    clockM.restart(); // ���� �̹����� ���� �ð� �����
                }
            }
        }
        else if (((Jheart >= 70 && Mheart < 70 && Hheart < 70 && EndLetter) || (Jheart >= 70 && Ch13HMJ[2] && EndChSec)) && Count == 13) {
            Screen1 = false;
            float elapsedTimeJ = clockJ.getElapsedTime().asSeconds();

            if (currentImageIndexJ < overlaySpritesJ.size())
            {
                // ��� �ð��� ������� ���� ���� �� ���
                float alphaJ = min(255.0f, (elapsedTimeJ / fadeDurationJ) * 255.0f);
                overlaySpritesJ[currentImageIndexJ].setColor(Color(255, 255, 255, static_cast<Uint8>(alphaJ)));

                if (alphaJ >= 255.0f)
                {
                    // ���� �̹����� ������ ���̵� �� �� �� ���� �̹����� �̵�
                    currentImageIndexJ++;
                    clockJ.restart(); // ���� �̹����� ���� �ð� �����
                }
            }
        }
        else if (((Hheart >= 70 && Mheart < 70 && Jheart < 70 && EndLetter) || (Hheart >= 70 && Ch13HMJ[0] && EndChSec)) && Count == 13) {
            float elapsedTimeH = clockH.getElapsedTime().asSeconds();

            if (currentImageIndexH < overlaySpritesH.size())
            {
                // ��� �ð��� ������� ���� ���� �� ���
                float alphaH = min(255.0f, (elapsedTimeH / fadeDurationH) * 255.0f);
                overlaySpritesH[currentImageIndexH].setColor(Color(255, 255, 255, static_cast<Uint8>(alphaH)));

                if (alphaH >= 255.0f)
                {
                    // ���� �̹����� ������ ���̵� �� �� �� ���� �̹����� �̵�
                    currentImageIndexH++;
                    clockH.restart(); // ���� �̹����� ���� �ð� �����
                }
            }
        }
        else if (((Hheart < 70 && Mheart < 70 && Jheart < 70) || Xheart >= 70) &&Count == 13 && EndLetter) {
            Screen1 = false;
            float elapsedTimeX = clockX.getElapsedTime().asSeconds();

            if (currentImageIndexX < overlaySpritesX.size())
            {
                // ��� �ð��� ������� ���� ���� �� ���
                float alphaX = min(255.0f, (elapsedTimeX / fadeDurationX) * 255.0f);
                overlaySpritesX[currentImageIndexX].setColor(Color(255, 255, 255, static_cast<Uint8>(alphaX)));

                if (alphaX >= 255.0f)
                {
                    // ���� �̹����� ������ ���̵� �� �� �� ���� �̹����� �̵�
                    currentImageIndexX++;
                    clockX.restart(); // ���� �̹����� ���� �ð� �����
                }
            }
        }

        if (((Jheart >= 70 && Mheart < 70 && Hheart < 70 && EndLetter) || (Jheart >= 70 && Ch13HMJ[2] && EndChSec)) && Count == 13) {
            app.draw(backgroundSprite);
            size_t i = 0;
            for (; i <= currentImageIndexJ && i < overlaySpritesJ.size(); ++i)
            {
                app.draw(overlaySpritesJ[i]);
            }
            if (i >= overlaySpritesJ.size()) app.draw(nextbutton[2]);
            end_chat = true;
        }
        else if (((Mheart >= 70 && Jheart < 70 && Hheart < 70 && EndLetter) || (Mheart >= 70 && Ch13HMJ[1] && EndChSec)) && Count == 13) {
            app.draw(backgroundSprite);
            size_t i = 0;
            for (; i <= currentImageIndexM && i < overlaySpritesM.size(); ++i)
            {
                app.draw(overlaySpritesM[i]);
            }
            if (i >= overlaySpritesM.size()) app.draw(nextbutton[2]);
            end_chat = true;
        }
        else if (((Hheart >= 70 && Mheart < 70 && Jheart < 70 && EndLetter) || (Hheart >= 70 && Ch13HMJ[0] && EndChSec)) &&Count == 13) {
            app.draw(backgroundSprite);
            size_t i = 0;
            for (; i <= currentImageIndexH && i < overlaySpritesH.size(); ++i)
            {
                app.draw(overlaySpritesH[i]);
            }
            if (i >= overlaySpritesH.size()) app.draw(nextbutton[2]);
            end_chat = true;
        }
        else if (((Hheart < 70 && Mheart < 70 && Jheart < 70) || Xheart >= 70) && Count == 13 && EndLetter) {
            app.draw(backgroundSprite);
            size_t i = 0;
            for (; i <= currentImageIndexX && i < overlaySpritesX.size(); ++i)
            {
                app.draw(overlaySpritesX[i]);
            }
            if (i >= overlaySpritesX.size()) app.draw(nextbutton[2]);
            end_chat = true;
        }


        if (((Jheart >= 70 && Mheart < 70 && Hheart < 70) || (Jheart >= 70 && Ch13HMJ[2] && EndChSec)) && Count == 13 && end_chatSec) {
            app.draw(EndBackSArr[0]);
            app.draw(realEnd);
            realEndBool = true;
        }
        else if (((Mheart >= 70 && Jheart < 70 && Hheart < 70 ) || (Mheart >= 70 && Ch13HMJ[1] && EndChSec)) && Count == 13 && end_chatSec) {
            app.draw(EndBackSArr[1]);
            app.draw(realEnd);
            realEndBool = true;
        }
        else if (((Hheart >= 70 && Mheart < 70 && Jheart < 70 ) || (Hheart >= 70 && Ch13HMJ[0] && EndChSec)) && Count == 13 && end_chatSec) {
            app.draw(EndBackSArr[2]);
            app.draw(realEnd);
            realEndBool = true;
        }
        else if (((Hheart < 70 && Mheart < 70 && Jheart < 70) || Xheart >= 70) && Count == 13 && end_chatSec) {
            app.draw(EndBackSArr[3]);
            app.draw(realEnd);
            realEndBool = true;
        }

        // ���� ��

        // �ֻ��� Click �̹���
        if (Screen1 && Count != 13 && clock.getElapsedTime() >= delayTime) {
            switch (Number) {
                // click2~7
            case 2:
                Click[0].setPosition(860, 446);
                app.draw(Click[0]);
                break;
            case 3:
                Click[0].setPosition(755, 446);
                app.draw(Click[0]);
                break;
            case 4:
                Click[0].setPosition(650, 446);
                app.draw(Click[0]);
                break;
            case 5:
                Click[0].setPosition(543, 446);
                app.draw(Click[0]);
                break;
            case 6:
                Click[0].setPosition(437, 446);
                app.draw(Click[0]);
                break;
            case 7:
                Click[0].setPosition(335, 446);
                app.draw(Click[0]);
                break;
                // click8~13
            case 8:
                Click[1].setPosition(309, 579);
                app.draw(Click[1]);
                break;
            case 9:
                Click[1].setPosition(347, 473);
                app.draw(Click[1]);
                break;
            case 10:
                Click[1].setPosition(347, 370);
                app.draw(Click[1]);
                break;
            case 11:
                Click[1].setPosition(347, 264);
                app.draw(Click[1]);
                break;
            case 12:
                Click[1].setPosition(347, 161);
                app.draw(Click[1]);
                break;
            case 13:
                Click[1].setPosition(309, 54);
                app.draw(Click[1]);
                break;
                // click14~19
            case 14:
                Click[2].setPosition(331, 175);
                app.draw(Click[2]);
                break;
            case 15:
                Click[2].setPosition(436, 175);
                app.draw(Click[2]);
                break;
            case 16:
                Click[2].setPosition(543, 175);
                app.draw(Click[2]);
                break;
            case 17:
                Click[2].setPosition(650, 175);
                app.draw(Click[2]);
                break;
            case 18:
                Click[2].setPosition(757, 175);
                app.draw(Click[2]);
                break;
            case 19:
                Click[2].setPosition(861, 175);
                app.draw(Click[2]);
                break;
                // click20~24
            case 20:
                Click[3].setPosition(863, 51);
                app.draw(Click[3]);
                break;
            case 21:
                Click[3].setPosition(828, 161);
                app.draw(Click[3]);
                break;
            case 22:
                Click[3].setPosition(828, 264);
                app.draw(Click[3]);
                break;
            case 23:
                Click[3].setPosition(828, 370);
                app.draw(Click[3]);
                break;
            case 24:
                Click[3].setPosition(828, 473);
                app.draw(Click[3]);
                break;
            }
        }
        // �߰���
        //sB
        if (sB1) {
            app.draw(s_background[0]);
            app.draw(s_nextbutton[0]);
        }
        else if (sB2) {
            app.draw(s_background[1]);
            app.draw(s_nextbutton[1]);
        }
        else if (sB3) {
            app.draw(s_background[2]);
        }

        // �߰���
        //rB
        if (rB1) app.draw(r_background[0]);
        else if (rB2) app.draw(r_background[1]);
        else if (rB3) app.draw(r_background[2]);
        else if (rB4) app.draw(r_background[3]);
        else if (rB_1_1) app.draw(r_background_2[0]);
        else if (rB_1_2) app.draw(r_background_2[1]);
        else if (rB_1_3) app.draw(r_background_2[2]);
        else if (rB_2_1) app.draw(r_background_1[0]);
        else if (rB_2_2) app.draw(r_background_1[1]);
        else if (rB_2_3) app.draw(r_background_1[2]);


        if (Hbasic1) {
            app.draw(background[18]);
        }
        if (Hbasic2) {
            app.draw(background[19]);
        }
        //Jbasic
        if (Jbasic1) {
            app.draw(background[20]);
        }
        if (Jbasic2) {
            app.draw(background[21]);
        }
        //Mbasic
        if (Mbasic1) {
            app.draw(background[22]);
        }
        if (Mbasic2) {
            app.draw(background[23]);
        }
        if (Xbasic) {
            app.draw(background[24]);
        }

        //Hch
        if (Hch1) {
            app.draw(background[1]);
        }
        else if (Hch2) {
            chText = true;
            app.draw(background[5]);
        }
        else if (Hch1_2) {
            chText = true;
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
            chText = true;
            app.draw(background[10]);
            Mch = true;
        }
        else if (Mch1_2) {
            chText = true;
            app.draw(background[7]);
        }
        else if (Mch1B) {
            app.draw(background[8]);
        }
        else if (Mch1G) {
            app.draw(background[9]);
        }
        else if (Mch2G) {
            app.draw(background[12]);
        }
        else if (Mch2B) {
            app.draw(background[11]);
        }

        //Jch
        if (Jch1) {
            app.draw(background[13]);
            chText = true;
        }
        else if (Jch2) {
            app.draw(background[16]);
            chText = true;
            Jch = true;
        }
        else if (JchB) {
            app.draw(background[14]);
        }
        else if (JchG) {
            app.draw(background[15]);

        }

        // Ch13
        if (Ch13) {
            Screen1 = false;
            app.draw(background[17]);
            for (int i = 0; i < 3; i++)   app.draw(chB13[i]);
        }


        if (Hch1 || Mch1) {
            app.draw(nextbutton[1]);
        }
        if (Hch1_2 || Hch2 || Mch1_2 || Mch2 || Jch1 || Jch2) {
            app.draw(chbutton[0]);
            app.draw(chbutton[1]);
        }
        if (HchB || HchG || Mch1B || Mch1G || Mch2B || Mch2G || JchB || JchG) {
            app.draw(nextbutton[2]);
            app.draw(chSB);
            chSBTEXT = true;
        }
        if ((Ch13 && Ch13B) || (Hbasic1 || Hbasic2) || (Jbasic1 || Jbasic2) || (Mbasic1 || Mbasic2 || Xbasic)
            || rB1 || rB2 || rB3 || rB4 || sB3 || rB_1_1 || rB_1_2 || rB_1_3 || rB_2_1 || rB_2_2 || rB_2_3) {
            app.draw(nextbutton[2]);
        }

        if (popup1 || popup2 || popup3 || popup4) {
            app.draw(PopUpBack);
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

        if (chText) {
            app.draw(text1);
            app.draw(text2);
        }
        if (chSBTEXT) {
            app.draw(chSBText);
        }

        if (!popup1 && !popup2 && !popup3 && !popup4 && Count != 13 && Screen1&&!sB1&&!sB2&&sB3) dice = true;
        app.display();
    }

    delete[] block;
    delete[] blockhover;
    delete[] button;

    return 0;
}