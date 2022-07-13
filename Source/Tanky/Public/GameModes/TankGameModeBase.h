#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Pawns/PawnTank.h"
#include "TankGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TANKY_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	APawnTank* PlayerTankRef = nullptr;
	uint16_t TurretsCount = 0;

	auto OnStartGame() -> void;
	auto OnGameOver(bool PlayerWon) -> void;

public:
	auto OnActorDestroy(AActor* Actor) -> void;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Game Configs")
	int32 StartDelay = 3;

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};