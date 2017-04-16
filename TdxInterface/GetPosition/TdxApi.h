#pragma once
#include "stdafx.h"

#include "QueueMap.h"
//�����ĵ�
//

//1.����API����TdxApi.dll�ļ��ĵ����������������º�����
//void   OpenTdx(); 
//void   CloseTdx();
//   int  Logon(char* IP, short Port, char* Version, char* AccountNo,char* JyPassword,   char* TxPassword, char* ErrInfo);
// void  Logoff(int ClientID);
// void  QueryData(int ClientID, int Category, char* Result, char* ErrInfo);
//void   QueryHistoryData(int ClientID, int Category, char* StartDate, char* EndDate, char* Result, char* ErrInfo);
// void  QueryDatas(int ClientID, int Category[], int Count, char* Result[], char* ErrInfo[]);
// void  SendOrder(int ClientID, int Category ,long PriceType,  char* Gddm,  char* Zqdm , float Price, long Quantity,  char* Result, char* ErrInfo);
// void  SendOrders(int ClientID, int Category[] , ,long PriceType[], char* Gddm[],  char* Zqdm[] , float Price[], long Quantity[],  int Count, char* Result[], char* ErrInfo[]);
// void  CancelOrder(int ClientID, char* hth, char* Result, char* ErrInfo);
// void  CancelOrders(int ClientID, char* hth[], int Count, char* Result[], char* ErrInfo[]);
// void  CancelOrder(int ClientID, char* ExchangeID, char* hth, char* Result, char* ErrInfo);//����֤ȯ��ͨ�˻��汾
// void  CancelOrders(int ClientID, char* ExchangeID[], char* hth[], int Count, char* Result[], char* ErrInfo[]);//����֤ȯ��ͨ�˻��汾
// void  GetQuote(int ClientID, char* Zqdm, char* Result, char* ErrInfo);
// void  GetQuotes(int ClientID, char* Zqdm[], int Count, char* Result[], char* ErrInfo[]);
// void  Repay(int ClientID, char* Amount, char* Result, char* ErrInfo);
// void  GetEdition(char* Result);

// void  QueryHKData(int ClientID, int Category, char* Result, char* ErrInfo);

//2.APIʹ������Ϊ: Ӧ�ó����ȵ���Init��ʼ��ͨ����ʵ����һ��ͨ����ʵ���¿���ͬʱ��¼��������˻���ÿ�������˻���֮Ϊ�ͻ���, ͨ��ClientID���ָ����ͻ���.
//ͨ������Logon���ClientID��Ȼ����Ե�������API�������в�ѯ���µ�; Ӧ�ó����˳�ʱӦ����Logoffע���ͻ���, ������Exit�˳�ͨ����ʵ��. 
//Init��Exit��������Ӧ�ó�����ֻ�ܱ�����һ��.

//3. ������������˵��

/// <summary>
/// ��ʼ��ͨ����ʵ��
/// </summary>
typedef void(__stdcall* OpenTdxDelegate)();


/// <summary>
/// �˳�ͨ����ʵ��
/// </summary>
typedef void(__stdcall* CloseTdxDelegate)();


/// <summary>
/// �����˻���¼
/// </summary>
/// <param name="IP">���׷�����IP</param>
/// <param name="Port">���׷������˿�</param>
/// <param name="Version">��������ͨ���ŵİ汾�ţ�������̫�ͣ�ȯ�̷���������Ϊʹ�õ�ͨ�������̫��Ҫ����</param>
/// <param name="AccountNo">�ʽ��˺�</param>
/// <param name="JyPassword">��������</param>
/// <param name="TxPassword">ͨѶ����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�����</param>
/// <returns>�ͻ���ID��ʧ��ʱ����-1</returns>
//typedef int(__stdcall* Tdx_LoginDelegate)(char* AccountNo, char* JyPassword, char* TxPassword, char* ErrInfo);
#ifdef TEST
typedef int(__stdcall* LogonDelegate)(char* IP, short Port, char* Version, short YybID, char* AccountNo, char* TradeAccount, char* JyPassword, char* TxPassword, char* ErrInfo);
#else
typedef int(__stdcall* LogonDelegate)(char* IP, short Port, char* Version, short YybID, unsigned char LoginMode, char* AccountNo, char* TradeAccount, char* JyPassword, char* TxPassword, char* ErrInfo);
#endif

/// <summary>
/// �����˻�ע��
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
typedef void(__stdcall* LogoffDelegate)(int ClientID);

/// <summary>
/// ��ѯ���ֽ�������
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��ʾ��ѯ��Ϣ�����࣬0�ʽ�  1�ɷ�   2����ί��  3���ճɽ�     4����   5�ɶ�����  6�������   7��ȯ���  8����֤ȯ</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* QueryDataDelegate)(int ClientID, int Category, char* Result, char* ErrInfo);



/// <summary>
/// ��ѯ�۹�ͨ���ֽ�������
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��ʾ��ѯ��Ϣ�����࣬0�ʽ�  1�ɷ�   2����ί��  3���ճɽ�     4����   5�ɶ�����  6�������   7��ȯ���  8����֤ȯ</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* QueryHKDataDelegate)(int ClientID, int Category, char* Result, char* ErrInfo);


/// <summary>
/// ��ѯ������ʷ����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��ʾ��ѯ��Ϣ�����࣬0��ʷί��  1��ʷ�ɽ�   2���</param>
/// <param name="StartDate">��ʾ��ʼ���ڣ���ʽΪyyyyMMdd,����2014��3��1��Ϊ  20140301
/// <param name="EndDate">��ʾ�������ڣ���ʽΪyyyyMMdd,����2014��3��1��Ϊ  20140301
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* QueryHistoryDataDelegate)(int ClientID, int Category, char* StartDate, char* EndDate, char* Result, char* ErrInfo);

/// <summary>
/// ��ѯ���ָ۹�ͨ��ʷ����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��ʾ��ѯ��Ϣ�����࣬0��ʷί��  1��ʷ�ɽ� </param>
/// <param name="StartDate">��ʾ��ʼ���ڣ���ʽΪyyyyMMdd,����2014��3��1��Ϊ  20140301
/// <param name="EndDate">��ʾ�������ڣ���ʽΪyyyyMMdd,����2014��3��1��Ϊ  20140301
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* QueryHKHistoryDataDelegate)(int ClientID, int Category, char* StartDate, char* EndDate, char* Result, char* ErrInfo);

/// <summary>
/// ������ѯ���ֽ�������,�����鴫��ÿ��ί�еĲ����������i��Ԫ�ر�ʾ��i����ѯ����Ӧ����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��Ϣ�����������, ��i��Ԫ�ر�ʾ��i����ѯ����Ϣ���࣬0�ʽ�  1�ɷ�   2����ί��  3���ճɽ�     4����   5�ɶ�����  6�������   7��ȯ���  8����֤ȯ</param>
/// <param name="Count">��ѯ�ĸ�����������ĳ���</param>
/// <param name="Result">�������ݵ�����, ��i��Ԫ�ر�ʾ��i��ί�еķ�����Ϣ. ��APIִ�з��غ�Result[i]�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">������Ϣ�����飬��i��Ԫ�ر�ʾ��i��ί�еĴ�����Ϣ. ��APIִ�з��غ��������ErrInfo[i]�����˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* QueryDatasDelegate)(int ClientID, int Category[], int Count, char* Result[], char* ErrInfo[]);



/// <summary>
/// ��ί�н���֤ȯ
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��ʾί�е����࣬0���� 1����  2��������  3��ȯ����   4��ȯ��ȯ   5��ȯ����  6��ȯ��ȯ</param>
/// <param name="PriceType">��ʾ���۷�ʽ 0  �Ϻ��޼�ί�� �����޼�ί�� 1���ڶԷ����ż۸�  2���ڱ������ż۸�  3���ڼ�ʱ�ɽ�ʣ�೷��  4�Ϻ��嵵����ʣ�� �����嵵����ʣ�� 5����ȫ��ɽ����� 6�Ϻ��嵵����ת�޼�
/// <param name="Gddm">�ɶ�����</param>
/// <param name="Zqdm">֤ȯ����</param>
/// <param name="Price">ί�м۸�</param>
/// <param name="Quantity">ί������</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* SendOrderDelegate)(int ClientID, int Category, int PriceType, char* Gddm, char* Zqdm, float Price, int Quantity, char* Result, char* ErrInfo);


/// <summary>
/// �¸۹�ͨί�н��׸۹�
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">��ʾί�е����࣬0���� 1����</param>
/// <param name="PriceType">��ʾ���۷�ʽ  2�����޼��� 3��ǿ�޼���
/// <param name="Zqdm">֤ȯ����</param>
/// <param name="Price">ί�м۸�</param>
/// <param name="Quantity">ί������</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* SendHKOrderDelegate)(int ClientID, int Category, int PriceType, int QuantityType, char* Gddm, char* Zqdm, char* Price, char* Quantity, char* Result, char* ErrInfo);


/// <summary>
/// ������ί�н���֤ȯ�������鴫��ÿ��ί�еĲ����������i��Ԫ�ر�ʾ��i��ί�е���Ӧ����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Category">ί����������飬��i��Ԫ�ر�ʾ��i��ί�е����࣬0���� 1����  2��������  3��ȯ����   4��ȯ��ȯ   5��ȯ����  6��ȯ��ȯ</param>
/// <param name="PriceType">��ʾ���۷�ʽ������,  ��i��Ԫ�ر�ʾ��i��ί�еı��۷�ʽ, 0  �Ϻ��޼�ί�� �����޼�ί�� 1���ڶԷ����ż۸�  2���ڱ������ż۸�  3���ڼ�ʱ�ɽ�ʣ�೷��  4�Ϻ��嵵����ʣ�� �����嵵����ʣ�� 5����ȫ��ɽ����� 6�Ϻ��嵵����ת�޼�
/// <param name="Gddm">�ɶ��������飬��i��Ԫ�ر�ʾ��i��ί�еĹɶ�����</param>
/// <param name="Zqdm">֤ȯ�������飬��i��Ԫ�ر�ʾ��i��ί�е�֤ȯ����</param>
/// <param name="Price">ί�м۸����飬��i��Ԫ�ر�ʾ��i��ί�е�ί�м۸�</param>
/// <param name="Quantity">ί���������飬��i��Ԫ�ر�ʾ��i��ί�е�ί������</param>
/// <param name="Count">ί�еĸ�����������ĳ���</param>
/// <param name="Result">�������ݵ����飬��i��Ԫ�ر�ʾ��i��ί�еķ�����Ϣ����APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">������Ϣ�����飬��i��Ԫ�ر�ʾ��i��ί�еĴ�����Ϣ����APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* SendOrdersDelegate)(int ClientID, int Category[], int PriceType[], char* Gddm[], char* Zqdm[], float Price[], int Quantity[], int Count, char* Result[], char* ErrInfo[]);


/// <summary>
/// ��ί��
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Gddm">�ɶ�����</param>
/// <param name="ExchangeID">������ID������Ͷ��� �����Ϻ�1������0  �� �����Ϻ�1������2</param>
/// <param name="hth">��ʾҪ����Ŀ��ί�еı��</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
///typedef void(__stdcall* CancelOrderDelegate)(int ClientID, char* hth, char* Result, char* ErrInfo);//����֤ȯ���ð汾
typedef void (WINAPI* CancelOrderDelegate)(int ClientID, char* ExchangeID, char* hth, char* Result, char* ErrInfo);//����֤ȯ��ͨ�汾
//typedef void (WINAPI* CancelOrderDelegate)(int ClientID,char* Gddm, char* ExchangeID, char* hth, char* Result, char* ErrInfo);


/// <summary>
/// �۹�ͨ��ί��
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Gddm">�ɶ�����</param>
/// <param name="ExchangeID">������ID������Ͷ��� �����Ϻ�1������0  �� �����Ϻ�1������2</param>
/// <param name="hth">ʾҪ����Ŀ��ί�еı��</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* CancelHKOrderDelegate)(int ClientID, char* hth, char* Result, char* ErrInfo);


/// <summary>
/// ������ί��, �����鴫��ÿ��ί�еĲ����������i��Ԫ�ر�ʾ��i����ί�е���Ӧ����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Gddm">�ɶ�����</param>
/// <param name="ExchangeID">������ID������Ͷ����Ϻ�1������0  �� �����Ϻ�1������2</param>
/// <param name="hth">ʾҪ����Ŀ��ί�еı��</param>
/// <param name="Count">ί�еĸ�����������ĳ���</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
///typedef void(__stdcall* CancelOrdersDelegate)(int ClientID, char* hth[], int Count, char* Result[], char* ErrInfo[]);//����֤ȯ���ð汾
typedef void (WINAPI* CancelOrdersDelegate)(int ClientID, char* ExchangeID[], char* hth[], int Count, char* Result[], char* ErrInfo[]);//����֤ȯ��ͨ�汾
//typedef void (WINAPI* CancelOrdersDelegate)(int ClientID, char* Gddm[], char* ExchangeID[], char* hth[], int Count, char* Result[], char* ErrInfo[]);

/// <summary>
/// ��ȡ֤ȯ��ʵʱ�嵵����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Zqdm">֤ȯ����</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* GetQuoteDelegate)(int ClientID, char* Zqdm, char* Result, char* ErrInfo);


/// <summary>
/// ��ȡ�۹ɵ���ؽ�����Ϣ
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Zqdm">֤ȯ����</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* GetHKStockTradeInfoDelegate)(int ClientID, int Category, char* Zqdm, char* Result, char* ErrInfo);

/// <summary>
/// ������ȡ֤ȯ��ʵʱ�嵵����
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Zqdm">֤ȯ����</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* GetQuotesDelegate)(int ClientID, char* Zqdm[], int Count, char* Result[], char* ErrInfo[]);


/// <summary>
/// ������ȯֱ�ӻ���
/// </summary>
/// <param name="ClientID">�ͻ���ID</param>
/// <param name="Amount">������</param>
/// <param name="Result">��APIִ�з��غ�Result�ڱ����˷��صĲ�ѯ����, ��ʽΪ������ݣ�������֮��ͨ��\n�ַ��ָ������֮��ͨ��\t�ָ���һ��Ҫ����1024*1024�ֽڵĿռ䡣����ʱΪ���ַ�����</param>
/// <param name="ErrInfo">��APIִ�з��غ�������������˴�����Ϣ˵����һ��Ҫ����256�ֽڵĿռ䡣û����ʱΪ���ַ�������ע����ʾ��Ҳ�ô���ʾ����������Ϣ��</param>
typedef void(__stdcall* RepayDelegate)(int ClientID, char* Amount, char* Result, char* ErrInfo);





class CTdxApi
{
public:
	CTdxApi(void);
	~CTdxApi(void);

	HMODULE m_TdxApiHMODULE;

	OpenTdxDelegate OpenTdx;
	CloseTdxDelegate CloseTdx;
	LogonDelegate Logon;
	LogoffDelegate Logoff;
	QueryDataDelegate QueryData;
	QueryDatasDelegate QueryDatas;
	QueryHistoryDataDelegate QueryHistoryData;
	SendOrderDelegate SendOrder;
	SendOrdersDelegate SendOrders;
	CancelOrderDelegate CancelOrder;
	CancelOrdersDelegate CancelOrders;
	GetQuoteDelegate GetQuote;
	GetQuotesDelegate GetQuotes;
	RepayDelegate Repay;


	QueryHKDataDelegate QueryHKData;
	QueryHKHistoryDataDelegate QueryHKHistoryData;
	GetHKStockTradeInfoDelegate GetHKStockTradeInfo;
	SendHKOrderDelegate SendHKOrder;
	CancelHKOrderDelegate CancelHKOrder;
};

