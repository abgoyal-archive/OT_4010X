
#ifndef UNIREPL_H
#define UNIREPL_H

#include "unicode/utypes.h"


U_NAMESPACE_BEGIN

class Replaceable;
class UnicodeString;
class UnicodeSet;

class U_I18N_API UnicodeReplacer /* not : public UObject because this is an interface/mixin class */ {

 public:

    /**
     * Destructor.
     * @stable ICU 2.4
     */
    virtual ~UnicodeReplacer();

    /**
     * Replace characters in 'text' from 'start' to 'limit' with the
     * output text of this object.  Update the 'cursor' parameter to
     * give the cursor position and return the length of the
     * replacement text.
     *
     * @param text the text to be matched
     * @param start inclusive start index of text to be replaced
     * @param limit exclusive end index of text to be replaced;
     * must be greater than or equal to start
     * @param cursor output parameter for the cursor position.
     * Not all replacer objects will update this, but in a complete
     * tree of replacer objects, representing the entire output side
     * of a transliteration rule, at least one must update it.
     * @return the number of 16-bit code units in the text replacing
     * the characters at offsets start..(limit-1) in text
     * @stable ICU 2.4
     */
    virtual int32_t replace(Replaceable& text,
                            int32_t start,
                            int32_t limit,
                            int32_t& cursor) = 0;

    /**
     * Returns a string representation of this replacer.  If the
     * result of calling this function is passed to the appropriate
     * parser, typically TransliteratorParser, it will produce another
     * replacer that is equal to this one.
     * @param result the string to receive the pattern.  Previous
     * contents will be deleted.
     * @param escapeUnprintable if TRUE then convert unprintable
     * character to their hex escape representations, \\uxxxx or
     * \\Uxxxxxxxx.  Unprintable characters are defined by
     * Utility.isUnprintable().
     * @return a reference to 'result'.
     * @stable ICU 2.4
     */
    virtual UnicodeString& toReplacerPattern(UnicodeString& result,
                                             UBool escapeUnprintable) const = 0;

    /**
     * Union the set of all characters that may output by this object
     * into the given set.
     * @param toUnionTo the set into which to union the output characters
     * @stable ICU 2.4
     */
    virtual void addReplacementSetTo(UnicodeSet& toUnionTo) const = 0;
};

U_NAMESPACE_END

#endif
