#if !defined(_IMODEM_CONTROLLER_H_)
#define _IMODEM_CONTROLLER_H_

class IModemController {
	public:
		static IModemController* Create(uint8_t typeId, uint8_t param1);
		virtual ~IModemController();

		virtual bool ExecuteModemContractFunc(uint8_t var1, uint8_t var2) = 0;

	protected:
		IModemController();
};

#endif // _IMODEM_CONTROLLER_H_

