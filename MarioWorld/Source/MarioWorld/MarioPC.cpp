// Fill out your copyright notice in the Description page of Project Settings.

#include "MarioPC.h"


AMarioPC::AMarioPC()
{
	Coins = 97;
	Lives = 4;
}

void AMarioPC::AddCoin()
{
	Coins += 1;
	CheckCoinAmount();
}

void AMarioPC::CheckCoinAmount()
{
	if (Coins == 100)
	{
		Coins = 0;
		AddLife();
	}

}

void AMarioPC::AddLife()
{
	Lives += 1;
}

void AMarioPC::RemoveLife()
{
	Lives -= 1;
}


