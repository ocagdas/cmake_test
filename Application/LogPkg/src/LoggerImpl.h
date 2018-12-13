#if !defined(_LOGGER_IMPL_H_)
#define _LOGGER_IMPL_H_

class LoggerImpl : public ILogger{
	public:
		LoggerImpl();
		virtual ~LoggerImpl();

		virtual bool LoggerContractFunc(uint8_t var1, uint8_t var2);
		virtual void LogMessage(const std::string& message);
	private:
};

#endif //_LOGGER_IMPL_H_
