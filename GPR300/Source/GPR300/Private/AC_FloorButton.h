#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_FloorButton.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UAC_FloorButton : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_FloorButton();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsPressed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FVector PressOffset;
};
