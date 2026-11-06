#include "HealthComponent.h"
#include "GameFramework/Actor.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	if (AActor* Owner = GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}
}

void UHealthComponent::HandleTakeAnyDamage(
	AActor* DamagedActor,
	float Damage,
	const UDamageType* DamageType,
	AController* InstigatedBy,
	AActor* DamageCauser)
{
	if (Damage <= 0.0f || bIsDead)
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	bIsDead = (Health <= 0.0f);

	OnHealthChanged.Broadcast(this, Health, -Damage, DamageType);
}

void UHealthComponent::Heal(float HealAmount)
{
	if (HealAmount <= 0.0f || bIsDead)
	{
		return;
	}

	const float PreviousHealth = Health;
	Health = FMath::Clamp(Health + HealAmount, 0.0f, MaxHealth);
	const float ActualDelta = Health - PreviousHealth;

	if (ActualDelta > 0.0f)
	{
		OnHealthChanged.Broadcast(this, Health, ActualDelta, nullptr);
	}
}
