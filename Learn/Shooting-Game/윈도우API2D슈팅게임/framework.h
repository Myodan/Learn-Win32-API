#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* FreeType 라이브러리 헤더 */
#include "font/ft2build.h"
#include FT_FREETYPE_H

/* FreeType 라이브러리 추가 */
#pragma comment (lib, "font/release/freetype.lib")

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

#include "graphic.h"
#include "Debug.h"
#include "BMP.h"
#include "Time.h"
#include "Random.h"
#include "Input.h"
#include "Text.h"
#include "Application.h"
#include "GameObject.h"
#include "Sprite.h"
#include "GameBG.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Animation.h"
#include "Ayako.h"
#include "BoxCollider.h"
#include "BulletExp.h"
#include "AyakoBullet.h"
#include "PlayerShadow.h"
#include "ShipExp.h"
#include "JetFire.h"
#include "Shield.h"
#include "PlayerBomb.h"
#include "BombExp.h"
#include "Stealth.h"
#include "StealthBullet.h"
#include "Boss.h"
#include "Rotor.h"
#include "Wing.h"
#include "Gun.h"
#include "WingGun.h"
#include "Radar.h"
#include "PartsExp.h"
#include "DeadBoss.h"
#include "GameOverSprite.h"
#include "BulletItem.h"
#include "BombItem.h"
#include "Scene.h"
#include "GameScene.h"
#include "EndingScene.h"
#include "EndingBG.h"
#include "TitleScene.h"
#include "TitleBG.h"
#include "GoHome.h"
#include "ObjectManager.h"
#include "SpawnManager.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "Button.h"
#include "StartBtn.h"
#include "QuitBtn.h"
#include "MiniQuitBtn.h"
#include "MiniPauseBtn.h"
#include "Menu.h"
#include "PlayerLifeIcon.h"
#include "BombIcon.h"
#include "EnergyBar.h"

#define BG_WIDTH  480
#define BG_HEIGHT 800