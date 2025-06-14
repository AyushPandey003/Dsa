import requests

# API Keys
NEWS_API_KEY = "c142629ef10a4b56aca8d55141f21e5b"
ALPHA_VANTAGE_API_KEY = "IX128VDP4ZAJRYZU"
FINNHUB_API_KEY = "d03q9ahr01qm4vp3c89gd03q9ahr01qm4vp3c8a0"
MARKETAUX_API_KEY = "emMtQtR1vOKpkJyeeGFd3tnEqYpBXm6NJoLmsfn3"
MARKETSTACK_API_KEY = "b1aba5a2a8833d4f15f0070da7e3a3d6"

# Function to test NewsAPI
def test_news_api():
    url = f"https://newsapi.org/v2/top-headlines?country=in&apiKey={NEWS_API_KEY}"
    try:
        response = requests.get(url)
        print("NewsAPI Response:")
        print(response.status_code)
        print(response.json())
    except Exception as e:
        print(f"NewsAPI Error: {e}")

# Function to test Alpha Vantage
def test_alpha_vantage():
    url = f"https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=IBM&interval=5min&apikey={ALPHA_VANTAGE_API_KEY}&datatype=csv"
    try:
        response = requests.get(url)
        print("Alpha Vantage Response:")
        print(response.status_code)
        print(response.json())
    except Exception as e:
        print(f"Alpha Vantage Error: {e}")

# Function to test Finnhub
def test_finnhub():
    url = f"https://finnhub.io/api/v1/quote?symbol=AAPL&token={FINNHUB_API_KEY}"
    try:
        response = requests.get(url)
        print("Finnhub Response:")
        print(response.status_code)
        print(response.json())
    except Exception as e:
        print(f"Finnhub Error: {e}")

# Function to test MarketAux
def test_marketaux():
    url = f"https://api.marketaux.com/v1/news/all?symbols=TSLA&api_token={MARKETAUX_API_KEY}"
    try:
        response = requests.get(url)
        print("MarketAux Response:")
        print(response.status_code)
        print(response.json())
    except Exception as e:
        print(f"MarketAux Error: {e}")

# Function to test Marketstack
def test_marketstack():
    url = f"http://api.marketstack.com/v1/eod?access_key={MARKETSTACK_API_KEY}&symbols=AAPL"
    try:
        response = requests.get(url)
        print("Marketstack Response:")
        print(response.status_code)
        print(response.json())
    except Exception as e:
        print(f"Marketstack Error: {e}")

# Run tests
if __name__ == "__main__":
    print("Testing API Keys...\n")
    test_news_api()
    print("\n" + "="*50 + "\n")
    test_alpha_vantage()
    print("\n" + "="*50 + "\n")
    test_finnhub()
    print("\n" + "="*50 + "\n")
    test_marketaux()
    print("\n" + "="*50 + "\n")
    test_marketstack()