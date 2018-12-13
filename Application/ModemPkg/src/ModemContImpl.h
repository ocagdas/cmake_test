#if !defined(_MODEM_CONTROLLER_IMPL_H_)
#define _MODEM_CONTROLLER_IMPL_H_

class ModemContImpl : public IModemController{
	public:
		ModemContImpl();
		virtual ~ModemContImpl();

		virtual bool ExecuteModemContractFunc(uint8_t var1, uint8_t var2);
	private:
		logpkg::ILogger* loggerInst;
};

#endif //_MODEM_CONTROLLER_IMPL_H_
