#include "SpeedPickup.h"
#include "Blaster/BlasterComponents/BuffComponent.h"
#include "Blaster/Character/BlasterCharacter.h"


void ASpeedPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	ABlasterCharacter* BlasterCharacter = Cast<ABlasterCharacter>(OtherActor);
	if (BlasterCharacter)
	{
		UBuffComponent* Buff = BlasterCharacter->GetBuff();
		if (Buff)
		{
			//为玩家应用速度BUFF
			Buff->BuffSpeed(BaseSpeedBuff, CrouchSpeedBuff, SpeedBuffTime);
		}
	}
	//摧毁
	Destroy();
}
