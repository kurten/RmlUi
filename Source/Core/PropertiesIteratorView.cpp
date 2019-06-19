/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "precompiled.h"
#include "../../Include/Rocket/Core/PropertiesIteratorView.h"
#include "PropertiesIterator.h"

namespace Rocket {
namespace Core {



PropertiesIteratorView::PropertiesIteratorView(std::unique_ptr<PropertiesIterator> ptr) : ptr(std::move(ptr)) {}

PropertiesIteratorView::~PropertiesIteratorView()
{}

PropertiesIteratorView& PropertiesIteratorView::operator++()
{
	++(*ptr);
	return *this;
}

PropertyId PropertiesIteratorView::GetId() const
{
	return (*(*ptr)).first;
}

const String& PropertiesIteratorView::GetName() const
{
	return Core::StyleSheetSpecification::GetPropertyName(GetId());
}

const Property& PropertiesIteratorView::GetProperty() const
{
	return (*(*ptr)).second;
}

bool PropertiesIteratorView::AtEnd() const {
	return ptr->AtEnd();
}

const PseudoClassList& PropertiesIteratorView::GetPseudoClassList() const
{
	static const PseudoClassList empty_pseudo_class_list;
	const PseudoClassList* pseudo_list_ptr = ptr->GetPseudoClassList();
	if (!pseudo_list_ptr)
		return empty_pseudo_class_list;

	return *pseudo_list_ptr;
}

}
}
