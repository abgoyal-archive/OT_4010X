

#include "config.h"
#include "JSPluginElementFunctions.h"

#include "Bridge.h"
#include "HTMLNames.h"
#include "HTMLPlugInElement.h"
#include "JSHTMLElement.h"
#include "runtime_object.h"

using namespace JSC;

namespace WebCore {

using namespace Bindings;
using namespace HTMLNames;

// Runtime object support code for JSHTMLAppletElement, JSHTMLEmbedElement and JSHTMLObjectElement.

static Instance* pluginInstance(Node* node)
{
    if (!node)
        return 0;
    if (!(node->hasTagName(objectTag) || node->hasTagName(embedTag) || node->hasTagName(appletTag)))
        return 0;
    HTMLPlugInElement* plugInElement = static_cast<HTMLPlugInElement*>(node);
    // The plugin element holds an owning reference, so we don't have to.
    Instance* instance = plugInElement->getInstance().get();
    if (!instance || !instance->rootObject())
        return 0;
    return instance;
}

static RuntimeObjectImp* getRuntimeObject(ExecState* exec, Node* node)
{
    Instance* instance = pluginInstance(node);
    if (!instance)
        return 0;
    return instance->createRuntimeObject(exec);
}

JSValue runtimeObjectGetter(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLElement* thisObj = static_cast<JSHTMLElement*>(asObject(slot.slotBase()));
    HTMLElement* element = static_cast<HTMLElement*>(thisObj->impl());
    RuntimeObjectImp* runtimeObject = getRuntimeObject(exec, element);
    return runtimeObject ? runtimeObject : jsUndefined();
}

JSValue runtimeObjectPropertyGetter(ExecState* exec, const Identifier& propertyName, const PropertySlot& slot)
{
    JSHTMLElement* thisObj = static_cast<JSHTMLElement*>(asObject(slot.slotBase()));
    HTMLElement* element = static_cast<HTMLElement*>(thisObj->impl());
    RuntimeObjectImp* runtimeObject = getRuntimeObject(exec, element);
    if (!runtimeObject)
        return jsUndefined();
    return runtimeObject->get(exec, propertyName);
}

bool runtimeObjectCustomGetOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot, JSHTMLElement* element)
{
    RuntimeObjectImp* runtimeObject = getRuntimeObject(exec, element->impl());
    if (!runtimeObject)
        return false;
    if (!runtimeObject->hasProperty(exec, propertyName))
        return false;
    slot.setCustom(element, runtimeObjectPropertyGetter);
    return true;
}

bool runtimeObjectCustomGetOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor, JSHTMLElement* element)
{
    RuntimeObjectImp* runtimeObject = getRuntimeObject(exec, element->impl());
    if (!runtimeObject)
        return false;
    if (!runtimeObject->hasProperty(exec, propertyName))
        return false;
    PropertySlot slot;
    slot.setCustom(element, runtimeObjectPropertyGetter);
    // While we don't know what the plugin allows, we do know that we prevent
    // enumeration or deletion of properties, so we mark plugin properties
    // as DontEnum | DontDelete
    descriptor.setDescriptor(slot.getValue(exec, propertyName), DontEnum | DontDelete);
    return true;
}

bool runtimeObjectCustomPut(ExecState* exec, const Identifier& propertyName, JSValue value, HTMLElement* element, PutPropertySlot& slot)
{
    RuntimeObjectImp* runtimeObject = getRuntimeObject(exec, element);
    if (!runtimeObject)
        return 0;
    if (!runtimeObject->hasProperty(exec, propertyName))
        return false;
    runtimeObject->put(exec, propertyName, value, slot);
    return true;
}

static JSValue JSC_HOST_CALL callPlugin(ExecState* exec, JSObject* function, JSValue, const ArgList& args)
{
    Instance* instance = pluginInstance(static_cast<JSHTMLElement*>(function)->impl());
    instance->begin();
    JSValue result = instance->invokeDefaultMethod(exec, args);
    instance->end();
    return result;
}

CallType runtimeObjectGetCallData(HTMLElement* element, CallData& callData)
{
    Instance* instance = pluginInstance(element);
    if (!instance || !instance->supportsInvokeDefaultMethod())
        return CallTypeNone;
    callData.native.function = callPlugin;
    return CallTypeHost;
}

} // namespace WebCore