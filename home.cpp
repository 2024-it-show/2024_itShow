#include <SFML/Graphics.hpp> 
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

int Number = 8; // 주사위 누적값 변수입니다. 24가 넘어가면 24를 빼줘야 해용
int Jheart = 40;
int Hheart = 40;
int Mheart = 40;
int Xheart = 0;
int diceCount = 0;


const unsigned int originalWidth = 1280;
const unsigned int originalHeight = 720;

RenderWindow app(VideoMode(originalWidth, originalHeight), "game");

bool Screen1 = true;


int main()
{

	Font font;
	auto a = font.loadFromFile("설레임.ttf");


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
	bool Screen1 = true;
	bool Hch1 = false, Hch1_2 = false, HchB = false, HchG = false, Hch2 = false;
	bool Mch1 = false, Mch1_2 = false, Mch1B = false, Mch1G = false, Mch2 = false, Mch2B = false, Mch2G = false;
	bool Jch1 = false, JchG = false, JchB = false, Jch2 = false, Jch = false;
	bool Hbasic1 = false, Hbasic2 = false, Jbasic1 = false, Jbasic2 = false, Mbasic1 = false, Mbasic2 = false, Xbasic = false;
	bool Ch13 = false;
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

	//주사위 시작
	int count = 0;
	Texture diceTextures[6];
	string filePath = "dice";
	for (int i = 0; i < 6; i++) {
		if (!diceTextures[i].loadFromFile(filePath + to_string(i + 1) + ".png")) {
			cerr << "Failed to load dice" << i + 1 << " texture!" << endl;
		}
	}

	// 주사위 스프라이트 생성 및 설정
	Sprite diceSprite; // 주사위 사진이 나오게 하는 변수 
	diceSprite.setScale(0.25f, 0.25f); //크기 
	diceSprite.setPosition(580, 300);  //위치 

	// 랜덤 시드 초기화
	srand(static_cast<unsigned int>(time(NULL)));
	bool dice = true;       //주사위가 다른 화면에서는 굴러가지 않도록 하는 변수입니당. 
	bool showImage1 = true;
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
	//진짜 
	diceSprite.setScale(0.25f, 0.25f); //크기 
	diceSprite.setPosition(580, 300);  //위치 
	diceSprite.setTexture(diceTextures[0]);
	int diceValue = 0;
	//아마 이게 가짜?
	dice1Sprite.setScale(0.25f, 0.25f); //크기 
	dice1Sprite.setPosition(580, 300);  //위치 
	dice1Sprite.setTexture(diceTextures1[0]);
	int dice1Value = 1;

	srand(static_cast<unsigned>(std::time(nullptr)));

	Clock clock;
	bool rolling = false;
	float timeAccumulator = 0.0f;
	const float updateTime = 0.2f;
	const float totalRollingTime = 0.5f;
	Time elapsedTime;
	Clock clock1;
	Time delayTime = sf::seconds(0.5f);


	//주사위 끝


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

	bool popup1 = false, popup2 = false, popup3 = false, popup4 = false;

	Texture popBack;
	popBack.loadFromFile("pop-back.png");
	Sprite PopUpBack;
	PopUpBack.setTexture(popBack);
	PopUpBack.setScale(0.25f, 0.25f);


	//text
	Text text1, text2;
	text1.setFont(font);
	text2.setFont(font);
	text1.setString(L"안녕하세요");
	text2.setString(L"안녕하세요");
	text1.setCharacterSize(120);
	text2.setCharacterSize(120);
	text1.setScale(0.25f, 0.25f);
	text2.setScale(0.25f, 0.25f);
	text1.setFillColor(sf::Color(67, 64, 64));
	text2.setFillColor(sf::Color(67, 64, 64));
	bool chText = false;

	Text chSBText;
	chSBText.setFont(font);
	chSBText.setString(L"안녕하세요");
	chSBText.setCharacterSize(144);
	chSBText.setScale(0.25f, 0.25f);
	chSBText.setFillColor(sf::Color(67, 64, 64));
	bool chSBTEXT = false;

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
	bool Ch13B = false, Ch13HMJ[3] = { false };


	Texture s_back[3]; // 시작배경
	s_back[0].loadFromFile("startB1.png");
	s_back[1].loadFromFile("startB2.png");
	s_back[2].loadFromFile("startB3.png");

	Sprite s_background[3];
	for (int i = 0; i < 3; i++) {
		s_background[i].setTexture(s_back[i]);
		s_background[i].setScale(0.25f, 0.25f);
	}

	bool sB1 = true; bool sB2 = false; bool sB3 = false;

	Texture s_button[3]; // 시작버튼
	s_button[0].loadFromFile("start1.png");
	s_button[1].loadFromFile("button1.png");

	Sprite s_nextbutton[2];
	for (int i = 0; i < 2; i++) {
		s_nextbutton[i].setTexture(s_button[i]);
		s_nextbutton[i].setScale(0.25f, 0.25f);
	}
	s_nextbutton[0].setPosition(535, 500);
	s_nextbutton[1].setPosition(950, 560);

	Texture s_buttonH[3]; // 시작버튼 호버
	s_buttonH[0].loadFromFile("start2.png");
	s_buttonH[1].loadFromFile("button2.png");

	// 랜덤
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

	Texture r_back_1[3]; // 랜덤 인물 선택
	r_back_1[0].loadFromFile("Random_UP_MJ.png");
	r_back_1[1].loadFromFile("Random_Up_JH.png");
	r_back_1[2].loadFromFile("Random_Up_HS.png");
	Sprite r_background_1[3];
	for (int i = 0; i < 3; i++) {
		r_background_1[i].setTexture(r_back_1[i]);
		r_background_1[i].setScale(0.25f, 0.25f);
	}

	Texture r_back_2[3]; // 랜덤 인물 선택
	r_back_2[0].loadFromFile("Random_Down_MJ.png");
	r_back_2[1].loadFromFile("Random_Down_JH.png");
	r_back_2[2].loadFromFile("Random_Down_HS.png");
	Sprite r_background_2[3];
	for (int i = 0; i < 3; i++) {
		r_background_2[i].setTexture(r_back_2[i]);
		r_background_2[i].setScale(0.25f, 0.25f);
	}

	bool rB1 = false;
	bool rB2 = false;
	bool rB3 = false;
	bool rB4 = false;

	bool rB_1 = false;
	bool rB_1_1 = false;
	bool rB_1_2 = false;
	bool rB_1_3 = false;

	bool rB_2 = false;
	bool rB_2_1 = false;
	bool rB_2_2 = false;
	bool rB_2_3 = false;

	// 여까지 추가됨


	// Click // 지수민소리 여기서 setPosition만 해주면 되는데 칸마다 다르게 해줘야 해
	// 그니까 Number 두고 switch나 if로 2부터 24까지(for문X) 조건 줘서 피그마 보고 x,y 따와서 세팅하면 돼용 
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

	// 재현 호감도
	Text JheartS;
	JheartS.setFont(font);
	JheartS.setCharacterSize(112);
	JheartS.setScale(0.25f, 0.25f);
	JheartS.setFillColor(sf::Color(255, 120, 135));
	JheartS.setPosition(130, 253);
	char buffer1[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함
	// 한솔 호감도
	Text HheartS;
	HheartS.setFont(font);
	HheartS.setCharacterSize(112);
	HheartS.setScale(0.25f, 0.25f);
	HheartS.setFillColor(sf::Color(103, 156, 68));
	HheartS.setPosition(1162, 253);
	char buffer2[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함
	// 민재 호감도
	Text MheartS;
	MheartS.setFont(font);
	MheartS.setCharacterSize(112);
	MheartS.setScale(0.25f, 0.25f);
	MheartS.setFillColor(sf::Color(13, 85, 109));
	MheartS.setPosition(130, 550);
	char buffer3[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함
	// X 호감도
	Text XheartS;
	XheartS.setFont(font);
	XheartS.setCharacterSize(112);
	XheartS.setScale(0.25f, 0.25f);
	XheartS.setFillColor(sf::Color(65, 58, 57));
	XheartS.setPosition(1162, 550);
	char buffer4[4]; // "%3d"는 최대 3자리까지 표시하므로 4자리 배열이 필요함

	// 엔딩
	bool EndChSec = false, Endch = false, end=false;

	bool EndLetter = false;
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
	sf::Clock clock2; // 애니메이션 시간 관리를 위한 시계
	bool animationStarted = false; // 애니메이션 시작 여부를 나타내는 변수
	bool animationEnded = false;

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
				sf::Vector2i newPosition((static_cast<int>(sf::VideoMode::getDesktopMode().width) - static_cast<int>(windowSize.x)) / 2, 0); // 화면의 상단 좌표를 사용하여 Y 좌표를 0으로 설정
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
				//진짜 주사위 굴리기
				int diceValue = rand() % 6;
				Number += diceValue + 1;
				count++;
				if (Number > 24) Number -= 24;
				cout << "Dice value: " << diceValue + 1 << endl;        //주사위 나온 값입니당
				cout << "Dice Num: " << Number << std::endl;       //주사위 누적 값입니당
				cout << "count: " << count << std::endl;

				// 주사위 값에 따라 스프라이트 변경
				diceSprite.setTexture(diceTextures[diceValue]);
				clock1.restart();
				dice = false;  // 주사위 굴릴 수 있게 하는 변수입니당! 만약 다른 코드가 끝난 후 주사위가 굴러가지 않는다면  dice = true;를 추가하면 될거에욤..!
			}
			//주사위 끝


			Vector2f mousePos = app.mapPixelToCoords(Mouse::getPosition(app));
			//주사위 끝
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
						if (i == 3 && Screen1 && Number == 4 && (diceCount != count + 1)) {
							showImage1 = true;
							Screen1 = false;
							Hch1 = true;
							diceCount = count + 1;
						}
						else if (i == 2 && Screen1 && Number == 3 && (diceCount != count + 1)) {
							showImage1 = true;
							Mbasic1 = true;
							Screen1 = false;
							Mheart -= 15;
							diceCount = count + 1;
						}
						else if (i == 4 && Screen1 && Number == 5 && (diceCount != count + 1)) {
							showImage1 = true;
							Jbasic1 = true;
							Screen1 = false;
							Jheart += 15;
							diceCount = count + 1;
						}
						else if (i == 6 && Screen1 && Number == 7 && (diceCount != count + 1)) {
							showImage1 = true;
							Hbasic1 = true;
							Screen1 = false;
							Hheart -= 15;
							diceCount = count + 1;
						}
						else if (i == 8 && Screen1 && Number == 9 && (diceCount != count + 1)) {
							showImage1 = true;
							Screen1 = false;
							Mch1 = true;
							Mheart += 15;
							diceCount = count + 1;
						}
						else if (i == 11 && Screen1 && Number == 12 && (diceCount != count + 1)) {
							showImage1 = true;
							Screen1 = false;
							Hch2 = true;
							text1.setString(L"전 카라멜 팝콘 좋아해요");
							text1.setPosition(862, 225);
							text2.setString(L"전 민트초코 팝콘 좋아해요");
							text2.setPosition(848, 452);
							diceCount = count + 1;
						}
						else if (i == 14 && Screen1 && Number == 15 && (diceCount != count + 1)) {
							showImage1 = true;
							Screen1 = false;
							Jch1 = true;
							text1.setString(L"가는데 10분 정도 걸리니까\n지금 나가야겠네요");
							text1.setPosition(845, 206);
							text2.setString(L"에이 천천히 가도 괜찮아요");
							text2.setPosition(848, 452);
							diceCount = count + 1;
						}
						else if (i == 17 && Screen1 && Number == 18 && (diceCount != count + 1)) {
							showImage1 = true;
							Hbasic2 = true;
							Screen1 = false;
							Hheart += 15;
							diceCount = count + 1;
						}
						else if (i == 18 && Screen1 && Number == 19 && (diceCount != count + 1)) {
							showImage1 = true;
							Screen1 = false;
							Mch2 = true;
							text1.setString(L"(장난스럽게) 하하\n이래서 그만두셨구나");
							text1.setPosition(882, 206);
							text2.setString(L"그래도 잘하시네요\n역시 선수 출신!");
							text2.setPosition(896, 433);
							diceCount = count + 1;
						}
						else if (i == 20 && Screen1 && Number == 21 && (diceCount != count + 1)) {
							showImage1 = true;
							Jch2 = true;
							Screen1 = false;
							text1.setString(L"아뇨, 이제 씻어야죠");
							text1.setPosition(888, 226);
							text2.setString(L"에이 괜찮아요~\n어차피 장갑 낄 건데요");
							text2.setPosition(875, 432);
							diceCount = count + 1;
						}
						else if (i == 12 && Screen1 && Number == 13 && (diceCount != count + 1)) {
							showImage1 = true;
							Ch13 = true;
							diceCount = count + 1;
						}
						else if (i == 7 && Screen1 && Number == 8 && (diceCount != count + 1)) {
							dice = false;
							showImage1 = true;
							popup1 = true;
							Hheart -= 10;
							Jheart -= 10;
							Mheart -= 10;
							diceCount = count + 1;
						}
						else if (i == 10 && Screen1 && Number == 11 && (diceCount != count + 1)) {
							showImage1 = true;
							Jbasic2 = true;
							Screen1 = false;
							Jheart -= 15;
							diceCount = count + 1;
						}
						else if (i == 15 && Screen1 && Number == 16 && (diceCount != count + 1)) {
							dice = false;
							showImage1 = true;
							popup2 = true;
							Hheart += 15;
							Jheart += 15;
							Mheart += 15;
							diceCount = count + 1;
						}
						else if (i == 19 && Screen1 && Number == 20 && (diceCount != count + 1)) {
							dice = false;
							showImage1 = true;
							popup3 = true;
							Xheart += 20;
							diceCount = count + 1;
						}
						else if (i == 22 && Screen1 && Number == 23 && (diceCount != count + 1)) {
							showImage1 = true;
							Mbasic2 = true;
							Screen1 = false;
							Mheart += 15;
							diceCount = count + 1;
						}
						else if (i == 23 && Screen1 && Number == 24 && (diceCount != count + 1)) {
							dice = false;
							showImage1 = true;
							popup4 = true;
							Hheart -= 15;
							Jheart -= 15;
							Mheart -= 15;
							diceCount = count + 1;
						}
						else if ((i == 13 || i == 1) && Screen1 && (Number == 2 || Number == 14) && (diceCount != count + 1)) {
							showImage1 = true;
							Xbasic = true;
							Screen1 = false;
							Xheart += 15;
							diceCount = count + 1;
						}
						else if ((i == 5 || i == 9 || i == 16 || i == 21) && Screen1 && (Number == 6 || Number == 10 || Number == 17 || Number == 22) && (diceCount != count + 1)) {
							showImage1 = true;
							diceCount = count + 1;
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
						if (i == 2&&EndLetter) {
							EndChSec = true; Endch = false;
						}
						if (i == 1 && Hch1) {
							Hch1 = false;
							Hch1_2 = true;
							text1.setString(L"이거 재미없나봐요\n저희 다른 거 볼까요? ");
							text1.setPosition(880, 206);
							text2.setString(L"그래도 이미 예매했는데\n그냥 볼까요? ");
							text2.setPosition(865, 433);
						}
						else if (i == 1 && Mch1) {
							Mch1 = false;
							Mch1_2 = true;
							text1.setString(L"김치가 다 떨어졌나요?\n하하 농담~");
							text1.setPosition(870, 206);
							text2.setString(L"혹시 주문이\n잘못 들어갔나요?");
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
								chSBText.setString(L"전 카라멜은\n     별로...");
								chSBText.setPosition(397, 192);
							}
							if (Hch1_2) {
								chSBText.setString(L"( 아.. 줏대가 없네 )");
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
								chSBText.setString(L"저도 민초\n좋아해요!");
								chSBText.setPosition(412, 192);
							}
							if (Hch1_2) {
								chSBText.setString(L"\t\t좋아요!\n(줏대있다!멋져)");
								chSBText.setPosition(370, 193);
							}
							Hheart += 20;
							chText = false;
							Hch1_2 = false;
							Hch2 = false;
							HchG = true;
						}
						if (i == 0 && (Mch1_2 || Mch2)) {
							if (Mch1_2) {
								chSBText.setString(L"  ( 저게 무슨\n말버릇이람..)");
								chSBText.setPosition(379, 187.99);
								Mch1B = true;
							}
							else if (Mch2) {
								chSBText.setString(L"\t부상 때문에\n잘 안되네요 ㅎㅎ;");
								chSBText.setPosition(360, 187.99);
								Mch2B = true;
							}
							Mheart -= 20;
							chText = false;
							Mch1_2 = false;
							Mch2 = false;
						}
						else if (i == 1 && (Mch1_2 || Mch2)) {
							if (Mch1_2) {
								chSBText.setString(L"( 아주 예의가\n   바르구만 )");
								chSBText.setPosition(386, 187.99);
								Mch1G = true;
							}
							else if (Mch2) {
								chSBText.setString(L"하하 아녜요\n  고마워요");
								chSBText.setPosition(397, 187.99);
								Mch2G = true;
							}
							Mheart += 20;
							chText = false;
							Mch1_2 = false;
							Mch2 = false;
						}
						if (i == 0 && (Jch1 || Jch)) {
							if (Jch1) {
								chSBText.setString(L"   아... 되게\n칼같으시네요");
								chSBText.setPosition(385, 187.99);
							}
							else if (Jch) {
								chSBText.setString(L"( 왜 저렇게\n깔끔떨지 ? )");
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
								chSBText.setString(L"( 여유롭네\n  멋있어!)");
								chSBText.setPosition(406, 193);
							}
							else if (Jch) {
								chSBText.setString(L"( 털털한 성격\n\t  좋다!)");
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
					if (chB13[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePos))&& !EndChSec) {
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
					if (Screen1&&count==13) {
						Screen1 = false;
						end = false;
						EndLetter = true;
					}
				}
			}
		}

		if (Number == 1 && count != 0) Number += 1;

		//주사위 시작 
		if (rolling&&count!=13) {
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

		//주사위 끝
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
			}//주사위
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

		//엔딩
		// 
		if (((Jheart >= 70 && Hheart >= 70) || (Jheart >= 70 && Mheart >= 70) || (Mheart >= 70 && Hheart >= 70)
			|| (Mheart >= 70 && Hheart >= 70 && Jheart >= 70)) &&EndLetter&&!EndChSec) {
			app.draw(EndBackS);
			Endch = true;
		}

		
		if (count == 13&&Screen1) {
			end = true;
			dice = false;
		}

		if (end && !animationStarted)
		{
			clock2.restart(); // 애니메이션 시간을 다시 시작
			animationStarted = true; // 애니메이션 시작
		}

		if (animationStarted && !animationEnded)
		{
			float time = clock2.getElapsedTime().asSeconds(); // 경과 시간 가져오기
			if (time <= 15.0f) // 애니메이션이 5초 동안 지속됨
			{
				float bounce = std::sin(time * 10) * 10; // 반동 효과 적용 (주기와 진폭 조정 가능)
				EndL.setPosition(finalX, finalY + bounce); // 스프라이트의 위치를 반동에 맞게 설정
			}
			else
			{
				EndL.setPosition(finalX, finalY); // 애니메이션이 끝난 후 스프라이트 위치 고정
				animationEnded = true; // 애니메이션 종료 표시
			}
		}

		if (end) {
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

		if (((Jheart >= 70 && Mheart < 70 && Hheart < 70 && EndLetter) || (Jheart >= 70 && Ch13HMJ[2] && EndChSec)) && count == 13) {
			app.draw(EndBackSArr[0]);
		}
		else if (((Mheart >= 70 && Jheart < 70 && Hheart < 70 && EndLetter) || (Mheart >= 70 && Ch13HMJ[1] && EndChSec)) && count == 13) {
			app.draw(EndBackSArr[1]);
		}
		else if (((Hheart >= 70 && Mheart < 70 && Jheart < 70 && EndLetter) || (Hheart >= 70 && Ch13HMJ[0] && EndChSec)) && count == 13) {
			app.draw(EndBackSArr[2]);
		}
		else if (((Hheart < 70 && Mheart < 70 && Jheart < 70) || Xheart >= 70) && count == 13 && EndLetter) {
			app.draw(EndBackSArr[3]);
		}
		// 엔딩 끝

		// 주사위 Click 이미지
		if (Screen1&&count!=13 && clock.getElapsedTime() >= delayTime) {
			switch (Number) {
				// click2~7
			case 2:
				Click[0].setPosition(867, 457);
				app.draw(Click[0]);
				break;
			case 3:
				Click[0].setPosition(761, 457);
				app.draw(Click[0]);
				break;
			case 4:
				Click[0].setPosition(655, 457);
				app.draw(Click[0]);
				break;
			case 5:
				Click[0].setPosition(549, 457);
				app.draw(Click[0]);
				break;
			case 6:
				Click[0].setPosition(443, 457);
				app.draw(Click[0]);
				break;
			case 7:
				Click[0].setPosition(337, 457);
				app.draw(Click[0]);
				break;
				// click8~13
			case 8:
				Click[1].setPosition(300, 582);
				app.draw(Click[1]);
				break;
			case 9:
				Click[1].setPosition(349.2, 474);
				app.draw(Click[1]);
				break;
			case 10:
				Click[1].setPosition(349.2, 368);
				app.draw(Click[1]);
				break;
			case 11:
				Click[1].setPosition(349.2, 262);
				app.draw(Click[1]);
				break;
			case 12:
				Click[1].setPosition(349.2, 156);
				app.draw(Click[1]);
				break;
			case 13:
				Click[1].setPosition(300, 54);
				app.draw(Click[1]);
				break;
				// click14~19
			case 14:
				Click[2].setPosition(337, 160);
				app.draw(Click[2]);
				break;
			case 15:
				Click[2].setPosition(443, 160);
				app.draw(Click[2]);
				break;
			case 16:
				Click[2].setPosition(549, 160);
				app.draw(Click[2]);
				break;
			case 17:
				Click[2].setPosition(655, 160);
				app.draw(Click[2]);
				break;
			case 18:
				Click[2].setPosition(761, 160);
				app.draw(Click[2]);
				break;
			case 19:
				Click[2].setPosition(867, 160);
				app.draw(Click[2]);
				break;
				// click20~24
			case 20:
				Click[3].setPosition(886, 54);
				app.draw(Click[3]);
				break;
			case 21:
				Click[3].setPosition(834, 156);
				app.draw(Click[3]);
				break;
			case 22:
				Click[3].setPosition(834, 262);
				app.draw(Click[3]);
				break;
			case 23:
				Click[3].setPosition(834, 368);
				app.draw(Click[3]);
				break;
			case 24:
				Click[3].setPosition(834, 474);
				app.draw(Click[3]);
				break;
			}
		}
		// 추가됨
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

		// 추가됨
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

		if (!popup1 && !popup2 && !popup3 && !popup4 && count != 13&&Screen1) dice = true;
		app.display();
	}

	delete[] block;
	delete[] blockhover;
	delete[] button;

	return 0;
}