

#ifndef BindingDOMWindow_h
#define BindingDOMWindow_h

#include "Frame.h"
#include "FrameLoadRequest.h"
#include "GenericBinding.h"
#include "Page.h"
#include "SecurityOrigin.h"

namespace WebCore {

template <class Binding>
class BindingDOMWindow {
public:
    typedef typename Binding::Value BindingValue;

    static Frame* createWindow(State<Binding>*,
                               Frame* callingFrame,
                               Frame* enteredFrame,
                               Frame* openerFrame,
                               const String& url,
                               const String& frameName,
                               const WindowFeatures& windowFeatures,
                               BindingValue dialogArgs);
};

// Implementations of templated methods must be in this file.

template <class Binding>
Frame* BindingDOMWindow<Binding>::createWindow(State<Binding>* state,
                                               Frame* callingFrame,
                                               Frame* enteredFrame,
                                               Frame* openerFrame,
                                               const String& url,
                                               const String& frameName,
                                               const WindowFeatures& windowFeatures,
                                               BindingValue dialogArgs)
{
    ASSERT(callingFrame);
    ASSERT(enteredFrame);

    if (Document* callingDocument = callingFrame->document()) {
        // Sandboxed iframes cannot open new auxiliary browsing contexts.
        if (callingDocument->securityOrigin()->isSandboxed(SandboxNavigation))
            return 0;
    }

    ResourceRequest request;

    // For whatever reason, Firefox uses the entered frame to determine
    // the outgoingReferrer.  We replicate that behavior here.
    String referrer = enteredFrame->loader()->outgoingReferrer();
    request.setHTTPReferrer(referrer);
    FrameLoader::addHTTPOriginIfNeeded(request, enteredFrame->loader()->outgoingOrigin());
    FrameLoadRequest frameRequest(request, frameName);

    // FIXME: It's much better for client API if a new window starts with a URL,
    // here where we know what URL we are going to open. Unfortunately, this
    // code passes the empty string for the URL, but there's a reason for that.
    // Before loading we have to set up the opener, openedByDOM,
    // and dialogArguments values. Also, to decide whether to use the URL
    // we currently do an allowsAccessFrom call using the window we create,
    // which can't be done before creating it. We'd have to resolve all those
    // issues to pass the URL instead of "".

    bool created;
    // We pass in the opener frame here so it can be used for looking up the
    // frame name, in case the active frame is different from the opener frame,
    // and the name references a frame relative to the opener frame, for example
    // "_self" or "_parent".
    Frame* newFrame = callingFrame->loader()->createWindow(openerFrame->loader(), frameRequest, windowFeatures, created);
    if (!newFrame)
        return 0;

    newFrame->loader()->setOpener(openerFrame);
    newFrame->page()->setOpenedByDOM();

    Binding::DOMWindow::storeDialogArgs(state, newFrame, dialogArgs);

    if (!protocolIsJavaScript(url) || BindingSecurity<Binding>::canAccessFrame(state, newFrame, true)) {
        KURL completedUrl =
            url.isEmpty() ? KURL(ParsedURLString, "") : completeURL(url);
        bool userGesture = processingUserGesture();

        if (created)
            newFrame->loader()->changeLocation(completedUrl, referrer, false, false, userGesture);
        else if (!url.isEmpty())
            newFrame->redirectScheduler()->scheduleLocationChange(completedUrl.string(), referrer, false, userGesture);
    }

    return newFrame;
}

} // namespace WebCore

#endif // BindingDOMWindow_h