#if !defined(_ILogger_H_)
#define _ILogger_H_

class ILogger {
	public:
		static ILogger* Create(uint8_t typeId);
		virtual ~ILogger();

		virtual bool LoggerContractFunc(uint8_t var1, uint8_t var2) = 0;
		virtual void LogMessage(const std::string& message) = 0;

	protected:
		ILogger();
};

#endif // _ILogger_H_

