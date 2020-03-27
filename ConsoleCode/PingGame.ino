//All functions specific to Ping go here

int ping_playerX;
int ping_moveSpeed;

int ping_ballX;
int ping_ballY;
int ping_ballSpeedX;
int ping_ballSpeedY;

int ping_score;
int ping_hiscore; //Stored in EEPROM @ 0

void playPing(){
  bool playing = true;
  start = false;
  
  //Reset variables
  ping_playerX = 145;
  ping_moveSpeed = 5;
  ping_ballX = 159;
  ping_ballY = 80;
  ping_ballSpeedX = 2 * pow(-1, random(1, 3)); //Randomizes staring X direction.
  ping_ballSpeedY = 2; //Positive Y means its falling
  ping_score = 0;
  ping_hiscore = EEPROM.read(0);
  
  initPing();

  while(playing){
    readInputs();
    while(start == false){
      readInputs();
      myGLCD.setColor(255, 255, 255); //WHITE
      myGLCD.setBackColor(0, 0, 0); //BLACK
      myGLCD.setFont(BigFont);
      myGLCD.print("Press Start", 70, 120);
      if(start){
        //Clear text
        myGLCD.setColor(0, 0, 0); //BLACK
        myGLCD.fillRect(70, 120, 260, 160);
      }
    }
    updatePing();

    //Increase speed every 10 score
    ping_ballSpeedX = (ping_ballSpeedX / abs(ping_ballSpeedX)) * (ping_score / 10 + 2);
    ping_ballSpeedY = (ping_ballSpeedY / abs(ping_ballSpeedY)) * (ping_score / 10 + 2);
  }
}

void initPing(){
  myGLCD.clrScr();
  
  //Title
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.setBackColor(255, 255, 255); //WHITE
  myGLCD.setFont(BigFont);
  myGLCD.print("Ping", 5, 5);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Score: 0", 100, 5);
  myGLCD.print("Hi-score: " + String(ping_hiscore), 200, 5);

  //Borders
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillRect(0, 34, 319, 38);
  myGLCD.fillRect(0, 38, 4, 239);
  myGLCD.fillRect(315, 38, 319, 239);

  //Draw Player
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillRect(ping_playerX, 190, ping_playerX + 40, 198);

  //Draw ball
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillCircle(ping_ballX, ping_ballY, 5);
  
}

void updatePing(){
  if(abs(joyValX) == 10){
    ping_movePlayer();
  }
  ping_moveBall();
  delay(20);
}

void ping_movePlayer(){
  //Update paddle position
  if(joyValX > 0 && ping_playerX < 315 - 40 - ping_moveSpeed){
    ping_playerX += ping_moveSpeed;
    
    //Clear trailing section
    myGLCD.setColor(0, 0, 0); //BLACK
    myGLCD.fillRect(ping_playerX - ping_moveSpeed, 190, ping_playerX, 198);
    
    //Draw leading section
    myGLCD.setColor(255, 255, 255); //WHITE
    myGLCD.fillRect(ping_playerX + 40 - ping_moveSpeed, 190, ping_playerX + 40, 198);
  }
  if(joyValX < 0 && ping_playerX > 4 + ping_moveSpeed){
    ping_playerX -= ping_moveSpeed;
    
    //Clear trailing section
    myGLCD.setColor(0, 0, 0); //BLACK
    myGLCD.fillRect(ping_playerX + 40, 190, ping_playerX + 40 + ping_moveSpeed, 198);
    
    //Draw leading section
    myGLCD.setColor(255, 255, 255); //WHITE
    myGLCD.fillRect(ping_playerX, 190, ping_playerX + 40, 198);
  }
}

void ping_moveBall(){
  //Clear old ball
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillCircle(ping_ballX, ping_ballY, 5);

  ping_ballX += ping_ballSpeedX;
  ping_ballY += ping_ballSpeedY;

  //Draw new ball
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillCircle(ping_ballX, ping_ballY, 5);

  //Check for colisions (5 is radius)
  if(ping_ballX - 5 + ping_ballSpeedX < 4){ //If it collides with left wall
    ping_ballSpeedX *= -1;
    player.play(2); //ping_hitWall
  }
  if(ping_ballX + 5 + ping_ballSpeedX > 315){ //If it collides with right wall
    ping_ballSpeedX *= -1;
    player.play(2); //ping_hitWall
  }
  if(ping_ballY - 5 + ping_ballSpeedY < 38){ //If it collides with top wall
    ping_ballSpeedY *= -1;
    player.play(2); //ping_hitWall
  }
  if(ping_ballY + 5 + ping_ballSpeedY > 190 && ping_ballY + 5 + ping_ballSpeedY < 198){ //If it collides with paddle
    if(ping_ballX - 1 >= ping_playerX && ping_ballX + 1 <= ping_playerX + 40){
      ping_ballSpeedY *= -1;
      ping_score += 1;
      player.play(3); //ping_hitPaddle

      //Show new score
      myGLCD.setColor(255, 255, 255); //WHITE
      myGLCD.setBackColor(0, 0, 0); //BLACK
      myGLCD.setFont(Retro8x16);
      myGLCD.print("Score: " + String(ping_score), 100, 5);
    }
  }
  if(ping_ballY > 239){ //If it falls through the bottom
    player.play(4); //ping_lose
    ping_endGame();
  }
}

void ping_endGame(){
  myGLCD.clrScr();
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.setColor(255, 255, 255); //WHITE
  if(ping_score > ping_hiscore){
    EEPROM.write(0, ping_score); //Saves high score
    myGLCD.setFont(BigFont);
    myGLCD.print("New Hi-score!", CENTER, 50);
  } else {
    myGLCD.setFont(BigFont);
    myGLCD.print("Score", CENTER, 50);
  }
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.print(String(ping_score), CENTER, 100);

  //Countdown
  delay(2000);
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Restarting in: 3", CENTER, 200);
  delay(1000);
  myGLCD.print("Restarting in: 2", CENTER, 200);
  delay(1000);
  myGLCD.print("Restarting in: 1", CENTER, 200);
  delay(1000);
  myGLCD.print("Restarting in: 0", CENTER, 200);
  delay(1000);
  playPing();
}
