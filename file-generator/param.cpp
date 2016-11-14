CShfeFtdcReqQryObjectAttrField field;
		memset(&field, 0, sizeof(field));
		CString csOid =GetObjectID();
		int index =csOid.Find(GetAttrType());
		csOid =csOid.Left(index -1);
		lstrcpyA(field.ObjectID, CT2A(csOid));////PuDian.Test.T-MN3750-B1_1B2_1-2M501
		lstrcpyA(field.AttrType, CT2A(GetAttrType()));//MEMUsage

		time_t timep;
		time(&timep);
		timep +=g_pSysMonitorApp->GetDataDispatcher().GetTimeOffset();
		time_t timep1 =timep -FRONTLENGTH*3600;
		struct tm *pGm = localtime(&timep);
		sprintf((char *)(field.EndTime),"%02d:%02d:%02d", pGm->tm_hour, pGm->tm_min, pGm->tm_sec);14:30:23
		sprintf((char *)(field.EndDate),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);20151204
		struct tm *pGm1 = localtime(&timep1);
		sprintf((char *)(field.StartTime),"%02d:%02d:%02d", pGm1->tm_hour, pGm1->tm_min, pGm1->tm_sec);14:30:23
		sprintf((char *)(field.StartDate),"%d%02d%02d" ,pGm1->tm_year+1900 ,pGm1->tm_mon+1 ,pGm1->tm_mday);20151203

		ReqQryObjectAttrTopic(&field, ++m_nRequestID);