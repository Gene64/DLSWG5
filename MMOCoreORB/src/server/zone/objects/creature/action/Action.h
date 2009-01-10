/*
 *	server/zone/objects/creature/action/Action.h generated by engine3 IDL compiler 0.55
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "engine/orb/DistributedObjectBroker.h"

class ActionCreature;

class MissionManagerImplementation;

class SceneObject;

class TangibleObject;

class Player;

class Creature;

class Action : public DistributedObjectStub {
public:
	Action(SceneObject* po, String& tky, int actMask, int tpr);

	void setActionKey(String& tky);

	String& getActionKey();

	void setPrereq(int tpr);

	void setMeetHasMission(String& tstr);

	void setMeetKillLimitList(String& tlist);

	void setActionMask(int tat);

	void execAction(Player* player);

	void addConvoScreen(String& screenID, String& leftBoxText, int numOptions, String& Options, String& optLinks);

	void setGiveItem(TangibleObject* tempTano);

	void setTakeItem(unsigned int crc, String& itemname, bool useParentMisoKey, String& withMisoKey);

protected:
	Action(DummyConstructorParameter* param);

	virtual ~Action();

	String _return_getActionKey;

	friend class ActionHelper;
};

class ActionImplementation;

class ActionAdapter : public DistributedObjectAdapter {
public:
	ActionAdapter(ActionImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setActionKey(String& tky);

	String& getActionKey();

	void setPrereq(int tpr);

	void setMeetHasMission(String& tstr);

	void setMeetKillLimitList(String& tlist);

	void setActionMask(int tat);

	void execAction(Player* player);

	void addConvoScreen(String& screenID, String& leftBoxText, int numOptions, String& Options, String& optLinks);

	void setGiveItem(TangibleObject* tempTano);

	void setTakeItem(unsigned int crc, String& itemname, bool useParentMisoKey, String& withMisoKey);

protected:
	String _param0_setActionKey__String_;
	String _param0_setMeetHasMission__String_;
	String _param0_setMeetKillLimitList__String_;
	String _param0_addConvoScreen__String_String_int_String_String_;
	String _param1_addConvoScreen__String_String_int_String_String_;
	String _param3_addConvoScreen__String_String_int_String_String_;
	String _param4_addConvoScreen__String_String_int_String_String_;
	String _param1_setTakeItem__int_String_bool_String_;
	String _param3_setTakeItem__int_String_bool_String_;
};

class ActionHelper : public DistributedObjectClassHelper, public Singleton<ActionHelper> {
	static ActionHelper* staticInitializer;

public:
	ActionHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<ActionHelper>;
};

class ActionServant : public DistributedObjectServant {
public:
	Action* _this;

public:
	ActionServant();
	virtual ~ActionServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*ACTION_H_*/
