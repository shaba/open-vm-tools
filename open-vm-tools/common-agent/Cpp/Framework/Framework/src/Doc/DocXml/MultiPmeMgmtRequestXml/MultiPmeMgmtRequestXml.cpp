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

#include "Doc/DocXml/CafCoreTypesXml/RequestHeaderXml.h"
#include "Doc/DocXml/MultiPmeMgmtRequestXml/MultiPmeMgmtBatchCollectionXml.h"

#include "Doc/CafCoreTypesDoc/CRequestHeaderDoc.h"
#include "Doc/MultiPmeMgmtRequestDoc/CMultiPmeMgmtBatchCollectionDoc.h"
#include "Doc/MultiPmeMgmtRequestDoc/CMultiPmeMgmtRequestDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/MultiPmeMgmtRequestXml/MultiPmeMgmtRequestXml.h"

using namespace Caf;

void MultiPmeMgmtRequestXml::add(
	const SmartPtrCMultiPmeMgmtRequestDoc multiPmeMgmtRequestDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("MultiPmeMgmtRequestXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(multiPmeMgmtRequestDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdVal =
			BasePlatform::UuidToString(multiPmeMgmtRequestDoc->getClientId());
		CAF_CM_VALIDATE_STRING(clientIdVal);
		thisXml->addAttribute("clientId", clientIdVal);

		const std::string requestIdVal =
			BasePlatform::UuidToString(multiPmeMgmtRequestDoc->getRequestId());
		CAF_CM_VALIDATE_STRING(requestIdVal);
		thisXml->addAttribute("requestId", requestIdVal);

		const SmartPtrCRequestHeaderDoc requestHeaderVal =
			multiPmeMgmtRequestDoc->getRequestHeader();
		CAF_CM_VALIDATE_SMARTPTR(requestHeaderVal);

		const SmartPtrCXmlElement requestHeaderXml =
			thisXml->createAndAddElement("requestHeader");
		RequestHeaderXml::add(requestHeaderVal, requestHeaderXml);

		const SmartPtrCMultiPmeMgmtBatchCollectionDoc multiPmeBatchCollectionVal =
			multiPmeMgmtRequestDoc->getMultiPmeBatchCollection();
		CAF_CM_VALIDATE_SMARTPTR(multiPmeBatchCollectionVal);

		const SmartPtrCXmlElement multiPmeBatchCollectionXml =
			thisXml->createAndAddElement("multiPmeBatchCollection");
		MultiPmeMgmtBatchCollectionXml::add(multiPmeBatchCollectionVal, multiPmeBatchCollectionXml);
	}
	CAF_CM_EXIT;
}

SmartPtrCMultiPmeMgmtRequestDoc MultiPmeMgmtRequestXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("MultiPmeMgmtRequestXml", "parse");

	SmartPtrCMultiPmeMgmtRequestDoc multiPmeMgmtRequestDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdStrVal =
			thisXml->findRequiredAttribute("clientId");
		UUID clientIdVal = CAFCOMMON_GUID_NULL;
		if (! clientIdStrVal.empty()) {
			BasePlatform::UuidFromString(clientIdStrVal.c_str(), clientIdVal);
		}

		const std::string requestIdStrVal =
			thisXml->findRequiredAttribute("requestId");
		UUID requestIdVal = CAFCOMMON_GUID_NULL;
		if (! requestIdStrVal.empty()) {
			BasePlatform::UuidFromString(requestIdStrVal.c_str(), requestIdVal);
		}

		const SmartPtrCXmlElement requestHeaderXml =
			thisXml->findRequiredChild("requestHeader");

		SmartPtrCRequestHeaderDoc requestHeaderVal;
		if (! requestHeaderXml.IsNull()) {
			requestHeaderVal = RequestHeaderXml::parse(requestHeaderXml);
		}

		const SmartPtrCXmlElement multiPmeBatchCollectionXml =
			thisXml->findRequiredChild("multiPmeBatchCollection");

		SmartPtrCMultiPmeMgmtBatchCollectionDoc multiPmeBatchCollectionVal;
		if (! multiPmeBatchCollectionXml.IsNull()) {
			multiPmeBatchCollectionVal = MultiPmeMgmtBatchCollectionXml::parse(multiPmeBatchCollectionXml);
		}

		multiPmeMgmtRequestDoc.CreateInstance();
		multiPmeMgmtRequestDoc->initialize(
			clientIdVal,
			requestIdVal,
			requestHeaderVal,
			multiPmeBatchCollectionVal);
	}
	CAF_CM_EXIT;

	return multiPmeMgmtRequestDoc;
}
