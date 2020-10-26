#include "Ref2LaEmoji.h"

USING_NS_CC;

void M_Dialog::initWithData(SD_Dialog* dialogdata)
{
	_border = dialogdata->getBorder();
	_Bspace = dialogdata->getBspace();
	_Lspace = dialogdata->getLSpace();
	_adjustSize = dialogdata->getAdjustSize();
	setScaleX(_adjustSize.x / getContentSize().width);
	setScaleY(_adjustSize.y / getContentSize().height);
}

M_Dialog* M_Dialog::createWithDialogData(SD_Dialog* dialogdata)
{
	M_Dialog *diolog = new (std::nothrow) M_Dialog();
	if (diolog && diolog->initWithFile(dialogdata->getFileName()))
	{
		diolog->autorelease();
		diolog->initWithData(dialogdata);
		return diolog;
	}
	CC_SAFE_DELETE(diolog);
	return nullptr;
}
/*
bool M_Dialog::init(int x)
{
	_sizeExpand = x;
	//_texture = "10.png";
    return true;
}
*/
