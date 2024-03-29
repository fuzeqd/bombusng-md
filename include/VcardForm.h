#pragma once

#include "HtmlView.h"
#include "JabberDataBlock.h"
#include "JabberDataBlockListener.h"
#include "boostheaders.h"
#include "Contact.h"

class VcardForm : public HtmlView {
private:
    VcardForm(){};
public:
    void vcardArrivedNotify(JabberDataBlockRef vcard);
    typedef boost::shared_ptr<VcardForm> ref;
    virtual void onWmUserUpdate();
	std::wstring user_id;
    static VcardForm::ref createVcardForm(HWND parent,
		const std::string &jid,
		ResourceContextRef rc, bool edit);


protected:
    std::string jid;

    virtual HBITMAP getImage(LPCTSTR url, DWORD cookie);
    virtual void onHotSpot(LPCSTR url, LPCSTR param);

    BOOL savePhoto(LPCTSTR path);
    void loadPhoto(LPCTSTR path);

    ImageRef img;
    DWORD cookie;

    bool editForm;

    enum FieldType {
        TXT=0,
        URL=1,
        TEXTBOX=2,
        MULTILINE=4
    };

    int detectMime(char *buf);

    void addHtmlField(const char *ns1, const char *ns2, const char* description, int flags=TXT);

    boost::weak_ptr<VcardForm> formRef;

    JabberDataBlockRef vcard;
    boost::weak_ptr<ResourceContext> rc;
    JabberDataBlockListenerRef listener;
};