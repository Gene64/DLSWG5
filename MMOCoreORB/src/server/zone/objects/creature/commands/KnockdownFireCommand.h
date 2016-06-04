/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef KNOCKDOWNFIRECOMMAND_H_
#define KNOCKDOWNFIRECOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "CombatQueueCommand.h"

class KnockdownFireCommand : public CombatQueueCommand {
public:

	KnockdownFireCommand(const String& name, ZoneProcessServer* server)
		: CombatQueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<WeaponObject*> weapon = creature->getWeapon();
			if (!weapon->isFlameThrower())
				return INVALIDWEAPON;

		return doCombatAction(creature, target);
	}

};

#endif //KNOCKDOWNFIRECOMMAND_H_
