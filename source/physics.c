#include <math.h>
#include <world.h>
#include <animation.h>

float gravity = 500;
float dt = 1/60;

void physicsUpdatePlayer() {
	for (int i = 0; i < 32; i++) {
		float playerHalfWidth = 6.5f;
		float playerHalfHeight = 14.0f;
		float objHalfWidth = world.elements[i].transform.scale.width/2;
		float objHalfHeight = world.elements[i].transform.scale.height/2;
		float playerCenterX = world.Player.transform.position.x + playerHalfWidth;
		float playerCenterY = world.Player.transform.position.y + playerHalfHeight;
		float objCenterX = world.elememts[i].transform.position.x + objHalfWidth;
		float objCenterY = world.elements[i].transform.position.y + objHalfHeight;
		float diffx = playerCenterX - objCenterX;
		float diffy = playerCenterY - objCenterY;
		if ((fabs(diffx) < playerHalfWidth + objHalfWidth) && (fabs(diffy) < playerHalfHeight + objHalfHeight) && world.elements[i].canCollide && (world.elememts[i].anchored || world.elements[i].mass <= world.Player.mass)) {
			if (diffx < diffy) {
				world.Player.transform.position.x += diffx;
				world.Player.transform.velocity.x = 0;
				world.Player.transform.velocity.y += 200 * dt;
			} else {
				world.Player.transform.position.y += diffy;
				world.Player.transform.velocity.y = 0;
				world.Player.transform.velocity.x -= 50 * dt;
			}
		}
	}
	world.Player.transform.position.x += world.transform.velocity.x * dt;
	world.Player.transform.velocity.y -= gravity * dt;
	world.Player.transform.position.y += world.transform.velocity.y * dt;
}
void physicsUpdateEnemy() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 32; j++) {
			float enemyHalfWidth = world.enemies[i].transform.scale.width/2;
			float enemyHalfHeight = world.enemies[i].transform.scale.height/2;
			float objHalfWidth = world.elements[j].transform.scale.width/2;
			float objHalfHeight = world.elements[j].transform.scale.height/2;
			float enemyCenterX = world.enemies[i].transform.position.x + playerHalfWidth;
			float enemyCenterY = world.enemies[i].transform.position.y + playerHalfHeight;
			float objCenterX = world.elememts[j].transform.position.x + objHalfWidth;
			float objCenterY = world.elements[j].transform.position.y + objHalfHeight;
			float diffx = enemyCenterX - objCenterX;
			float diffy = enemyCenterY - objCenterY;
			if ((fabs(diffx) < enemyHalfWidth + objHalfWidth) && (fabs(diffy) < enemyHalfHeight + objHalfHeight) && world.elements[i].canCollide && (world.elememts[i].anchored || world.elements[j].mass <= world.enemies[i].mass)) {
				if (diffx < diffy) {
					world.enemies[i].transform.position.x += diffx;
					world.enemies[i].transform.velocity.x = 0;
					world.enemies[i].transform.velocity.y += 50 * dt;
				} else {
					world.enemies[i].transform.position.y += diffy;
					world.enemies[i].transform.velocity.y = 0;
					world.enemies[i].transform.velocity.x -= 50 * dt;
				}
			}
		}
	}
	float playerHalfWidth = 6.5f;
	float playerHalfHeight = 14.0f;
	float playerCenterX = world.Player.transform.position.x + playerHalfWidth;
	float playerCenterY = world.Player.transform.position.y + playerHalfHeight;
	diffx = playerCenterX - enemyCenterX;
	diffy = playerCenterY - enemyCenterY;
	if ((fabs(diffx) < enemyHalfWidth + playerHalfWidth) && (fabs(diffy) < enemyHalfHeight + playerHalfHeight) && world.elements[i].canCollide && (world.elememts[i].anchored || world.elements[j].mass <= world.enemies[i].mass)) {
		if (diffx > 0) {
			if (world.Player.cooldown <= 0) {
				world.Player.health -= world.enemies[i].power * (1/world.Player.defense);
				world.Player.cooldown += 120;
				//world.Player.velocity.x
			}
		} else {
			if (world.Player.cooldown <= 0) {
				world.Player.health -= world.enemies[i].power * (1/world.Player.defense);
				world.Player.cooldown += 120;
			}
		}
	}
	world.enemies[i].transform.position.x += world.transform.velocity.x * dt;
	world.enemies[i].transform.velocity.y -= gravity * dt;
	world.enemies[i].transform.position.y += world.transform.velocity.y * dt;
}
