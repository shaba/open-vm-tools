/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (c) 2012 Vmware, Inc.  All rights reserved.
 *  -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DiagTypesDoc/CDiagDeleteValueDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/DiagTypesXml/DiagDeleteValueXml.h"

using namespace Caf;

void DiagDeleteValueXml::add(
	const SmartPtrCDiagDeleteValueDoc diagDeleteValueDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DiagDeleteValueXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(diagDeleteValueDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string jobIdVal =
			BasePlatform::UuidToString(diagDeleteValueDoc->getJobId());
		CAF_CM_VALIDATE_STRING(jobIdVal);
		thisXml->addAttribute("jobId", jobIdVal);

		const std::string fileAliasVal = diagDeleteValueDoc->getFileAlias();
		CAF_CM_VALIDATE_STRING(fileAliasVal);
		thisXml->addAttribute("fileAlias", fileAliasVal);

		const std::string valueNameVal =
			diagDeleteValueDoc->getValueName();
		CAF_CM_VALIDATE_STRING(valueNameVal);

		const SmartPtrCXmlElement valueNameXml =
			thisXml->createAndAddElement("valueName");
		valueNameXml->setValue(valueNameVal);
	}
	CAF_CM_EXIT;
}

SmartPtrCDiagDeleteValueDoc DiagDeleteValueXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DiagDeleteValueXml", "parse");

	SmartPtrCDiagDeleteValueDoc diagDeleteValueDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string jobIdStrVal =
			thisXml->findRequiredAttribute("jobId");
		UUID jobIdVal = CAFCOMMON_GUID_NULL;
		if (! jobIdStrVal.empty()) {
			BasePlatform::UuidFromString(jobIdStrVal.c_str(), jobIdVal);
		}

		const std::string fileAliasStrVal =
			thisXml->findRequiredAttribute("fileAlias");
		const std::string fileAliasVal = fileAliasStrVal;

		const SmartPtrCXmlElement valueNameXml =
			thisXml->findRequiredChild("valueName");

		std::string valueNameVal;
		if (! valueNameXml.IsNull()) {
			valueNameVal = valueNameXml->getValue();
		}

		diagDeleteValueDoc.CreateInstance();
		diagDeleteValueDoc->initialize(
			jobIdVal,
			fileAliasVal,
			valueNameVal);
	}
	CAF_CM_EXIT;

	return diagDeleteValueDoc;
}
