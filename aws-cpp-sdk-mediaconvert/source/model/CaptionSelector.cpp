﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/mediaconvert/model/CaptionSelector.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace MediaConvert
{
namespace Model
{

CaptionSelector::CaptionSelector() : 
    m_languageCode(LanguageCode::NOT_SET),
    m_languageCodeHasBeenSet(false),
    m_sourceSettingsHasBeenSet(false)
{
}

CaptionSelector::CaptionSelector(const JsonValue& jsonValue) : 
    m_languageCode(LanguageCode::NOT_SET),
    m_languageCodeHasBeenSet(false),
    m_sourceSettingsHasBeenSet(false)
{
  *this = jsonValue;
}

CaptionSelector& CaptionSelector::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("languageCode"))
  {
    m_languageCode = LanguageCodeMapper::GetLanguageCodeForName(jsonValue.GetString("languageCode"));

    m_languageCodeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("sourceSettings"))
  {
    m_sourceSettings = jsonValue.GetObject("sourceSettings");

    m_sourceSettingsHasBeenSet = true;
  }

  return *this;
}

JsonValue CaptionSelector::Jsonize() const
{
  JsonValue payload;

  if(m_languageCodeHasBeenSet)
  {
   payload.WithString("languageCode", LanguageCodeMapper::GetNameForLanguageCode(m_languageCode));
  }

  if(m_sourceSettingsHasBeenSet)
  {
   payload.WithObject("sourceSettings", m_sourceSettings.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace MediaConvert
} // namespace Aws
