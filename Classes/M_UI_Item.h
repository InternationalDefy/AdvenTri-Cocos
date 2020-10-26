#ifndef __M_UI_ITEM__
#define __M_UI_ITEM__

#include "cocos2d.h"

USING_NS_CC;

class M_DispatchParser;
class M_CallbackParser;

class UI_Item :public Node
{
private:
	Rect _itemRect;
	bool _responed;
	Vector<Sprite*> _sprite;
	int _spriteNum;
	int _responseNum;
	bool _indiActive;
	//int _opacityTo;
	Vector<FiniteTimeAction*> _responseBegin;
	Vector<FiniteTimeAction*> _enterAction;
	Vector<FiniteTimeAction*> _quitAction;
	Vector<FiniteTimeAction*> _responseEnd;
	std::string _type;
	std::vector<M_DispatchParser*> _dispatchParser;
	std::vector<M_CallbackParser*> _callbackParser;

	std::vector<M_DispatchParser*> _activedDispatchParser;
	std::vector<M_CallbackParser*> _activedCallbackParser;
	void activeEventListeners();
	void deactiveEventListeners();
	//create && init;
public:
	CREATE_FUNC(UI_Item);
	bool init();
	//basic activities
private:
	void responseSprite(int index, Sprite* sp);
public:
	void responseItem();
	void responseSprite(int index);
	void responseEnd();
	void enterItem();
	void enterSprite(int index);
	void enterSprite(int index, Sprite* sp);
	void quitItem();

	void removeFromParent();
public:
	//getters && setters
public:
	//void setOpacityTo(int opt){ _opacityTo = opt; }
	Vector<Sprite*>* getSprites(){ return &_sprite; }
	bool isResponsed(){ return _responed; }
	void setType(const std::string& type){ _type = type; return; }
	std::string getType(){ return _type; }
	Sprite* getResponsedSprite()
	{
		if (_responed)
		{
			return _sprite.at(_responseNum);
		}
		else 
		{
			log("Cant Get Responsed Sprite when UNRESPONSED");
			return NULL;
		}
	}
	void pushResponseBeginAction(FiniteTimeAction* action)
	{
		if (!action)
		{
			log("No!!!!!!");
			return;
		}
		_responseBegin.pushBack(action);
		return;
	}
	void pushEnterAction(FiniteTimeAction* action)
	{
		if (!action)
		{
			log("No!!!!!!!");
			return;
		}
		_enterAction.pushBack(action);
	}
	void pushQuitAction(FiniteTimeAction* action)
	{
		if (!action)
		{
			log("No!!!!!");
			return;
		}
		_quitAction.pushBack(action);
		return;
	}
	void pushResponseEndAction(FiniteTimeAction* action){
		if (!action)
		{
			log("No!!!!!!");
			return;
		}
		_responseEnd.pushBack(action);
	}
	void pushSprite(Sprite* sp)
	{
		_spriteNum += 1;
		_itemRect = _itemRect.unionWithRect(sp->getBoundingBox());
		_sprite.pushBack(sp);
		addChild(sp);
	}
	void setIndiActive(bool act){ _indiActive = act; }

	void pushDispatchParser(M_DispatchParser*);
	void pushCallbackParser(M_CallbackParser*);

	Rect getSpriteBoundingBoxAtUILayer();

	Node* getLayer(){ return getParent()->getLayer(); }
	const Node* getLayer() const { return getParent()->getLayer(); }

};


#endif