#include "CustomCharacter.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ACustomCharacter::ACustomCharacter()
//: ControlInput()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACustomCharacter::BeginPlay()
{
	Super::BeginPlay();

	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void ACustomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	ControlInput->Bind(InputComponent);
	
	//Bind controls
	//Input_Jump        = &InputComponent->BindAction("Jump", EInputEvent::IE_Pressed);
	//Input_GroundPound = &InputComponent->BindAction("GroundPound");
}